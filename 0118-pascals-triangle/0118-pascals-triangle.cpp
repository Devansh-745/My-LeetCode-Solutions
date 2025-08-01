class Solution {
public:
    int memoize(int r, int c, vector<vector<int>>& dp, int n){
        if(c==0 || c==r) return dp[r][c]=1;
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c]=memoize(r-1, c-1, dp, n) + memoize(r-1, c, dp, n);
    }

    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            vector<int> row;
            for(int j=0; j<=i; j++){
                row.push_back(memoize(i, j, dp, n));
            }
            res.push_back(row);
        }
        return res;
    }
};
