class Solution {
private:
    void solve(string digits , vector<string>& map , string output , int index , vector<string> &ans){
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }
        int num = digits[index] - '0';
        string mapped = map[num];

        for(int j=0 ; j<mapped.size() ; j++){
            output.push_back(mapped[j]);
            solve(digits , map , output , index+1 , ans);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        string ouput = "";
        int index = 0;
        solve(digits , map , ouput , index , ans);
        return ans;
    }
};