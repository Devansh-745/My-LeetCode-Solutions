class Solution {
public:
    void neighbourchecker(vector<vector<int>>& board, int i, int j, int &live, int &dead, int m, int n){
        if(j+1<n){
            if(board[i][j+1]==1 || board[i][j+1]==3) live++;
            else dead++;
            if(i-1>=0){
                if(board[i-1][j+1]==1|| board[i-1][j+1]==3) live++;
                else dead++;
            }
            if(i+1<m){
                if(board[i+1][j+1]==1|| board[i+1][j+1]==3) live++;
                else dead++;
            }
        }
        if(i+1<m){
            if(board[i+1][j]==1 || board[i+1][j]==3) live++;
            else dead++;
        }
        if(i-1>=0){
            if(board[i-1][j]==1 || board[i-1][j]==3) live++;
            else dead++;
        }
        if(j-1>=0){
            if(board[i][j-1]==1 || board[i][j-1]==3) live++;
            else dead++;
            if(i-1>=0){
                if(board[i-1][j-1]==1 || board[i-1][j-1]==3) live++;
                else dead++;
            }
            if(i+1<m){
                if(board[i+1][j-1]==1 || board[i+1][j-1]==3) live++;
                else dead++;
            }
        }
    }
    /*
        0: Dead now, dead in the next generation.
        1: Live now, dead in the next generation.
        2: Dead now, live in the next generation.
        3: Live now, live in the next generation.
    */
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int live=0;
                int dead=0;
                neighbourchecker(board, i, j, live, dead, m, n);
                if(board[i][j]==1 || board[i][j]==3){
                    if(live<2){
                        board[i][j]=1;
                    }
                    else if(live==2 || live==3){
                        board[i][j]=3;
                    }
                    else if(live>3){
                        board[i][j]=1;
                    }
                }
                else{
                    if(live==3){
                        board[i][j]=2;
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==2 || board[i][j]==3){
                    board[i][j]=1;
                }
                else if(board[i][j]==0 || board[i][j]==1){
                    board[i][j]=0;
                }
            }
        }
        return;
    }
};