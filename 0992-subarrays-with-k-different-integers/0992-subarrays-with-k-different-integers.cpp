class Solution {
public:
    int helper(vector<int>& nums, int k){
        if(k==0) return 0;
        int n = nums.size();
        map<int,int> mpp;
        int l=0,r=0,count=0,sum=0;
        
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
    
        
    
};