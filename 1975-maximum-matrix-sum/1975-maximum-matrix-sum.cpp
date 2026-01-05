class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long sum=0;
        int neg=0;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]<0){
                    neg++;
                }
                mini=min(abs(matrix[i][j]), mini);
                sum+=abs(matrix[i][j]);
            }
        }
        if(neg%2==0) return sum;
        return sum-2*mini;
    }
};