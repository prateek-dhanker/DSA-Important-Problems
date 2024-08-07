#include <bits/stdc++.h>
using namespace std;


vector<int> computelps(string &pat,int m){
            vector<int> lps(m);
            lps[0] = 0;
            int len = 0, i=1;
            while(i<m){
                if(pat[i] == pat[len])
                    lps[i++] = ++len;
                
                else{
                    if(len)
                        len = lps[len-1];
                    else
                        i++;
                }
            }
            return lps; 
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            int n = txt.length() , m = pat.length();
            
            vector<int> lps = computelps(pat,m);
            
            vector<int> res;
            int i=0 , j=0;
            while((n-i) >= (m-j)){
                if(txt[i] == pat[j]){
                    i++;j++;
                }
                if(j == m){
                    res.push_back(i-m+1);
                    j = lps[j-1];
                }
                else if(i<n && pat[j]!=txt[i]){
                    if(j)
                        j = lps[j-1];
                    else
                        i++;
                }
            }
            return res;
            
        }