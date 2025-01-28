class Solution {
public:
vector<int> dx={0, 1, 0, -1};
vector<int> dy={1, 0, -1, 0};
    int dfs(int i, int j, vector<vector<bool>>& visit, vector<vector<int>>& grid, int m, int n){
        visit[i][j]=true;
        int allpaths=grid[i][j];
        for(int p=0; p<4; p++){
            if(i+dx[p]<m && j+dy[p]<n && i+dx[p]>=0 && j+dy[p]>=0 && grid[i+dx[p]][j+dy[p]]!=0 && !visit[i+dx[p]][j+dy[p]]){
                allpaths+=dfs(i+dx[p], j+dy[p], visit, grid, m, n);
            }
        }
        return allpaths;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]>0 && !visit[i][j]){
                    maxi=max(dfs(i, j, visit, grid, m, n), maxi);
                }
            }
        }
        return maxi;
    }
};