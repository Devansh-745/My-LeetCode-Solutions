class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            vector<int> freq(10, 0);
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    freq[board[i][j]-'0']++;
                    if(freq[board[i][j]-'0']>1) return false;
                } 
            }
        }
        for(int i=0; i<9; i++){
            vector<int> freq(10, 0);
            for(int j=0; j<9; j++){
                if(board[j][i]!='.'){
                    freq[board[j][i]-'0']++;
                    if(freq[board[j][i]-'0']>1) return false;
                }
            }
        }
        //important>>
        for(int box=0; box<9; box++){
            vector<int> freq(10, 0);
            int row = (box / 3) * 3;
            int col = (box % 3) * 3;
            for(int i=row; i<row+3; i++){
                for(int j=col; j<col+3; j++){
                    if(board[i][j]!='.'){
                        freq[board[i][j]-'0']++;
                        if(freq[board[i][j]-'0']>1) return false;
                    }
                }
            }
        }
        return true;
    }
};