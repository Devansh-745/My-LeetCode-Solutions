class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int cursum=nums[0];
        int maxsum=0;
        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]){
                maxsum=max(maxsum, cursum);
                cursum=0;
            }
            cursum+=nums[i];
        }
        return max(maxsum, cursum);
    }
};