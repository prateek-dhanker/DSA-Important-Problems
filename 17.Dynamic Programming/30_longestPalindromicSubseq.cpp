int longestCommonSubsequence(string text1, string text2) {
        vector<int> curr(text2.size()+1 , 0) , next(text2.size()+1 , 0);
        
        for(int i=text1.size()-1 ; i>=0;i--){
            for(int j=text2.size()-1; j>=0;j--){
                int ans;
                if(text1[i] == text2[j])
                    ans = 1+next[j+1];
                else
                    ans = max(curr[j+1] , next[j]);
                
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0]; // next[0]
    }
    int longestPalindromeSubseq(string s) {
        string revstr = s;
        reverse(revstr.begin() , revstr.end());

        return longestCommonSubsequence(s , revstr);
    }