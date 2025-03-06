class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> freq(n*n+2, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[grid[i][j]]++;
            }
        }
        int a=-1;
        int b=-1;
        for(int i=1; i<=n*n; i++){
            if(freq[i]==0){
                b=i;
            }
            else if(freq[i]==2){
                a=i;
            }
        }
        return {a, b};
    }
};