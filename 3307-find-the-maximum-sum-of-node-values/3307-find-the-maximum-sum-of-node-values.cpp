class Solution {
public:
    long long memoize(int i, int even, vector<int>& nums, int k, vector<vector<long long>>& dp){
        if(i==nums.size()){
            if(even==1) return 0;
            else return INT_MIN;
        }
        if(dp[i][even]!=-1) return dp[i][even];

        long long doxor= (nums[i]^k) +memoize(i+1, even^1, nums, k, dp);
        long long noxor= nums[i] +memoize(i+1, even, nums, k, dp);

        return dp[i][even]=max(doxor, noxor);
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return memoize(0, 1, nums, k, dp);
    }
};