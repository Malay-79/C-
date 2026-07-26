class Solution {
public:
    void solve(int indx, vector<vector<int>> &ans, vector<int> &ds, vector<int>& nums){
        if(indx==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[indx]);
        solve(indx+1,ans,ds,nums);
        ds.pop_back();
        solve(indx+1,ans,ds,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,ans,ds,nums);
        return ans;        
    }
};