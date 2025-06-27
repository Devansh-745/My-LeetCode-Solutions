class Solution {
public:
    int memoiz(vector<int>& nums, int i, vector<int>& dp, int n){
        if(i==n-1) return nums[n-1];
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+memoiz(nums, i+2, dp, n);
        int notpick=memoiz(nums, i+1, dp, n);

        return dp[i]=max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1, 0);
        // return memoiz(nums, 0, dp, n);
        int frontone=nums[n-1];
        int fronttwo=0;
        for(int i=n-2; i>=0; i--){
            int pick=nums[i]+fronttwo;
            int notpick=frontone;
            int cur=max(pick, notpick);
            fronttwo=frontone;
            frontone=cur;
        }
        return frontone;
    }
};