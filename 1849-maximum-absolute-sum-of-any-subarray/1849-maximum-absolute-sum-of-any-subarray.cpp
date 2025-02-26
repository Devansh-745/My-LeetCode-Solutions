class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int cursum=nums[0];
        int maxsum=nums[0];
        for(int i=1; i<n; i++){
            cursum=max(nums[i], cursum+nums[i]);
            maxsum=max(maxsum, cursum);
        }
        cursum=nums[0];
        int minsum=nums[0];
        for(int i=1; i<n; i++){
            cursum=min(nums[i], cursum+nums[i]);
            minsum=min(minsum, cursum);
        }
        return max(abs(minsum), abs(maxsum));
    }
};