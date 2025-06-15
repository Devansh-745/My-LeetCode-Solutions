class Solution {
public:
    vector<int> dx={1, 0, -1, 0};
    vector<int> dy={0, 1, 0, -1};
    bool escape(vector<vector<int>>& cells, int mid, int row, int col){
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for(int i=0; i<mid; i++){
            int fx=cells[i][0]-1;
            int fy=cells[i][1]-1;
            grid[fx][fy]=1; //flood
        }
        bool flag=false;
        for(int i=0; i<col; i++){
            if(grid[row-1][i]==0){
                flag=true;
                break;
            }
        }
        if(flag==false) return false; //last row is flooded 
        for(int i=0; i<col; i++){
            if(grid[0][i]==0){
                vector<vector<bool>> visit(row, vector<bool>(col, false));
                visit[0][i]=true;
                queue<pair<int, int>> q;
                q.push({0, i});
                while(!q.empty()){
                    int curx=q.front().first;
                    int cury=q.front().second;
                    q.pop();
                    if(curx==row-1) return true;

                    for(int z=0; z<4; z++){
                        int newx=curx+dx[z];
                        int newy=cury+dy[z];
                        if(newx<row && newx>=0 && newy<col && newy>=0 && !visit[newx][newy] && grid[newx][newy]==0){
                            q.push({newx, newy});
                            visit[newx][newy]=true;
                        }
                    }
                }
            } 
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=row*col; //number of days
        int high=n;
        int low=0;
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(escape(cells, mid, row, col)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};