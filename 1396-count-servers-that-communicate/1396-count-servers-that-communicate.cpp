class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<pair<int, int>> loc;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    loc.push_back({i, j});
                }
            }
        }
        int count=0;
        for(int i=0; i<loc.size(); i++){
            int x= loc[i].first;
            int y= loc[i].second;
            for(int j=0; j<loc.size(); j++){
                if(i==j) continue;
                else{
                    if(loc[j].first==x || loc[j].second==y){
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};