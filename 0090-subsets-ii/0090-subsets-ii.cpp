class Solution {
public:
    void findsubsets(int indx,vector<int> &nums,vector<vector<int>> &ans,vector<int> &ds){
        ans.push_back(ds);
        for(int i=indx;i<nums.size();i++){
            if(i!=indx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            findsubsets(i+1,nums,ans,ds);
            ds.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findsubsets(0,nums,ans,ds);
        return ans;
        
    }
};