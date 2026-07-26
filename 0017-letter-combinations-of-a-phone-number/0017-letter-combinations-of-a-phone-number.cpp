class Solution {
public:
    void solve(int indx,string &digits,string &temp,unordered_map<char,string> &mpp,vector<string> &result){
        if(indx==digits.size()){
            result.push_back(temp);
            return;
        }
        char ch = digits[indx];
        string str = mpp[ch];
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            solve(indx+1,digits,temp,mpp,result);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> result;
        unordered_map<char,string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        string temp = "";
        solve(0,digits,temp,mpp,result);
        return result;
        
    }
};