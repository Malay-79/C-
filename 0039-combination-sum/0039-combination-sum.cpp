class Solution {
public:
    void findcombination(int indx , int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){
        if(indx==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[indx]<=target){
            ds.push_back(arr[indx]);
            findcombination(indx,target-arr[indx],arr,ans,ds);
            ds.pop_back();
        }
        findcombination(indx+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(0,target,candidates,ans,ds);
        return ans;
        
    }
};