class Solution {
public:
    // void solve(int indx, vector<vector<int>> &ans, vector<int> &ds, vector<int>& nums){
    //     if(indx==nums.size()){
    //         ans.push_back(ds);
    //         return;
    //     }
    //     ds.push_back(nums[indx]);
    //     solve(indx+1,ans,ds,nums);
    //     ds.pop_back();
    //     solve(indx+1,ans,ds,nums);
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> ans;
        // vector<int> ds;
        // solve(0,ans,ds,nums);
        // return ans;
        int n=nums.size();
        int noofsubsets = 1<<n;
        vector<vector<int>> ans;
        vector<int> ds;
        
        for(int num=0; num < noofsubsets ; num++){
            
            for(int i=0;i<n;i++){
                if((num & (1<<i))!=0){
                    ds.push_back(nums[i]);
                }
            }
            ans.push_back(ds);
            ds.clear();
            
        }
        return ans;        
    }
};