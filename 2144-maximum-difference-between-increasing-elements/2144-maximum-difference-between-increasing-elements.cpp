class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxdiff=INT_MIN;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]<=mini){
                mini=nums[i];
            }
            else{
                maxdiff=max(maxdiff, nums[i]-mini);
            }
        }
        if(maxdiff==INT_MIN) return -1;
        return maxdiff;
    }
};