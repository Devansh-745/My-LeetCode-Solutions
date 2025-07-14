class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int ogcolor=image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc]=color;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        visit[sr][sc]=true;

        vector<int> dx={0, 1, 0, -1};
        vector<int> dy={1, 0, -1, 0};

        while(!q.empty()){
            int curx=q.front().first;
            int cury=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int newx=curx+dx[i];
                int newy=cury+dy[i];
                if(newx>=0 && newy>=0 && newx<m && newy<n && !visit[newx][newy] && image[newx][newy]==ogcolor){
                    visit[newx][newy]=true;
                    image[newx][newy]=color;
                    q.push({newx, newy});
                }
            }
        }
        return image;
    }
};