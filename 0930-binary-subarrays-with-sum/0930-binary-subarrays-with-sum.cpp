class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int n = nums.size();
        int l=0,r=0,count=0,sum=0;
        if(goal<0) return 0;
        while(r<n){
            sum = sum + nums[r];
            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};