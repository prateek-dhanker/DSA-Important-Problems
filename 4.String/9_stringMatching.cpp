#include <bits/stdc++.h>
using namespace std;

//Robin-Karp
class Solution {
  public:
    vector<int> search(string pattern, string text) {
        // code here.
        int n = text.size(), m = pattern.size();
        int d = 27, q = 101;
        int h = 1;
        for(int i=0;i<m-1;i++)
            h = (h*d)%q;
        
        int t=0, p=0;
        for(int i=0;i<m;i++){
            p = (p*d + (pattern[i]-'a'))%q;
            t = (t*d + (text[i]-'a'))%q;
        }
        
        vector<int> res;
        for(int i=0;i<=n-m;i++){
            if(p==t){
                bool matched = true;
                for(int j=0;j<m;j++)
                    if(pattern[j]!=text[i+j]){
                        matched = false;
                        break;
                    }
                
                if(matched)
                    res.push_back(i+1);
            }
            if(i!=n-m){
                t = ((t - h*(text[i]-'a'))*d + (text[i+m]-'a'))%q;
                if(t<0)
                    t += q;
            }
        }
        
        return res;
    }
};

//kmp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        vector<int> lps(m,0);

        int i=1,len = 0; //len - length of previous lps 
        while(i<m){
            if(needle[len] == needle[i])
                lps[i++] = ++len;
            

            else{
                if(len==0)  
                    lps[i++] = 0;
                else
                    len = lps[len-1];
            }
        }
        i=0;
        int j=0;
        while(n-i >= m-j){
            if(haystack[i] == needle[j]){
                i++; j++;
            }
            else{
                if(j==0)
                    i++;
                else
                    j = lps[j-1];
            }

            if(j == m){
                return i-m; //if return one

                //if more than one
                // res.push_back(i-m);
                // j = len[m-1]; 
            }
        }

        return -1;
        // return res;
    }
};