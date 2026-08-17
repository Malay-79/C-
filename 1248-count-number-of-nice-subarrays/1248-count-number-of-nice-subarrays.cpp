class Solution {
public:
    int helper(vector<int>& nums, int k){
        int n = nums.size();
        int l=0,r=0,count=0,sum=0;
        if(k<0) return 0;
        while(r<n){
            sum = sum + (nums[r]%2);
            while(sum > k){
                sum = sum - (nums[l]%2);
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};