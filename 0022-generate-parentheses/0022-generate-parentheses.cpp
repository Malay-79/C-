class Solution {
public:
    bool isvalid(string s){
        int balance=0;
        for(char ch : s){
            if(ch=='(') balance++;
            else balance--;
            if(balance < 0 ) return false;
        }
        return balance==0;
    }
    void Generate(int n , string curr , vector<string> &result){
        if(curr.size() == 2*n ){
            if(isvalid(curr)) result.push_back(curr);
            return;
        }
        Generate(n,curr+')',result);
        Generate(n,curr+'(',result);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        Generate(n,"",result);
        return result;
    }
};