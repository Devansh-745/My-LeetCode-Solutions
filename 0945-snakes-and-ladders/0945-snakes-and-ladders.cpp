class Solution {
public:
    //important function
    pair<int, int> getcoords(int cellnum, vector<vector<int>>& board, int n){
        int row=(cellnum-1)/n;
        int col=(cellnum-1)%n;
        int colact;
        if(row%2==0) colact=col;
        else colact=n-col-1;
        return {n-row-1, colact};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<bool> visit(n*n+1, false);
        queue<pair<int, int>> q; //position, stepcount
        q.push({1, 0});
        visit[1]=true;

        while(!q.empty()){
            int cur=q.front().first;
            int count=q.front().second;
            q.pop();
            if(cur==n*n) return count;
            for(int i=1; i<=6; i++){
                int next=cur+i;
                if(next>n*n) break;

                pair<int, int> coords= getcoords(next, board, n);
                int r=coords.first;
                int c=coords.second;
                int dest;
                if(board[r][c]==-1) dest=next;
                else dest=board[r][c];
                if(!visit[dest]){
                    q.push({dest, count+1});
                    visit[dest]=true;
                }
            }
        }
        return -1; //not possible to reach 
    }
};