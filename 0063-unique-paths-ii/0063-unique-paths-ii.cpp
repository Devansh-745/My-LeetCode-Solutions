class Solution {
public:
    int memoiz(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {

        //if (i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0; //obstacle found
        if (i==0 && j==0) return 1; 
        if (i<0 || j<0) return 0; 

        if (dp[i][j]!=-1) return dp[i][j];
        int up=0;
        int left=0;

        if( i-1>=0 && obstacleGrid[i-1][j]!=1) up= memoiz(i-1, j, obstacleGrid, dp);
        if(j-1>=0 && obstacleGrid[i][j-1]!=1) left= memoiz(i, j-1, obstacleGrid, dp);

        return dp[i][j] = up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); // number of rows
        int n = obstacleGrid[0].size(); // number of columns
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return memoiz(m - 1, n - 1, obstacleGrid, dp);
    }
};
