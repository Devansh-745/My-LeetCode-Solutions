class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int left=0;
        int right=0;
        int mini=INT_MAX;
        int whites=0;
        while(right<n){
            if(blocks[right]=='W') whites++;
            if(right-left+1==k){
                mini=min(mini, whites);
                if(blocks[left]=='W') whites--;
                left++;
            }
            right++;
        }
        return mini;
    }
};