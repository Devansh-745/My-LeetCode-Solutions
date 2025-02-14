class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int n=points.size();
        int maxsum=0;
        int lsum=0;
        int rsum=0;
        for(int i=0; i<k; i++){
            lsum+=points[i];
            maxsum=lsum;
        }
        int r=n-1;
        for(int i=k-1; i>=0; i--){
            lsum-=points[i];
            rsum+=points[r];
            r--;
            int val=lsum+rsum;
            maxsum=max(maxsum, val);
        }
        return maxsum;
    }
};