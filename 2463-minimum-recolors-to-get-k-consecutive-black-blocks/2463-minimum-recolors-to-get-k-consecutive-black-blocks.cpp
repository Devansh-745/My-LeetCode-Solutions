class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int left=0;
        int right=k-1;
        int mini=INT_MAX;
        while(right<n){
            int cur=0;
            for(int i=left; i<=right; i++){
                if(blocks[i]=='W') cur++;
            }
            mini=min(mini, cur);
            left++;
            right++;
        }
        return mini;
    }
};