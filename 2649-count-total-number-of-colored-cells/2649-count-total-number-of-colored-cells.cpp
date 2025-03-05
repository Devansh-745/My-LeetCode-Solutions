class Solution {
public:
    long long coloredCells(int n) {
        long long i=1;
        long long ans=1;
        while(i<n){
            ans+=(i)*4;
            i++;
        }
        return ans;
    }
};