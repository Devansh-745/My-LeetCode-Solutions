class Solution {
public:
/*
Since XORs must be applied to both nodes of an edge, the number of nodes that are XORed must always be even.

So this DP is checking all valid subsets of nodes where the number of XORed nodes is even, and tries all combinations recursively, keeping only valid ones and choosing the maximum total sum.
*/
    long long memoize(int i, int even, vector<int>& nums, int k, vector<vector<long long>>& dp){
        if(i==nums.size()){
            if(even==1) return 0;
            else return INT_MIN;
            //If we’ve finished checking all nodes (i == n):

            //If the number of XORed nodes is even, return 0 (valid case).

            //If odd, return INT_MIN (invalid configuration – 
            //XORed odd number of nodes → not achievable).
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
    /*
    XORing a node value with k once flips it to a new value.

    XORing it again brings it back.

    So, each node can be toggled an even number of times (0, 2, 4, ...) or odd number 
    of times (1, 3, 5, ...).

    Since we can only perform XOR on both nodes of an edge at the same time, the total 
    number of nodes that are XORed an odd number of times must be even.
    */
};