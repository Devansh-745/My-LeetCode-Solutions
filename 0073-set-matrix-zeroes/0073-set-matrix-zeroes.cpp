class Solution {
public:
    void modifier(vector<vector<int>>& matrix, int curi, int curj, int m, int n){
        for(int i=0; i<m; i++){
            if(matrix[i][curj]!=0) matrix[i][curj]=1e8;
        }
        for(int j=0; j<n; j++){
            if(matrix[curi][j]!=0) matrix[curi][j]=1e8;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    modifier(matrix, i, j, m, n);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1e8){
                    matrix[i][j]=0;
                }
            }
        }
        return;
    }
};