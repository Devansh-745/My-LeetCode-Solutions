class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int minc=0;
        for(int i=0; i<n; i++){
            int inc=1;
            int prev=nums[i];
            for(int j=i+1; j<n; j++){
                if(nums[j]>prev){
                    inc++;
                }
                else break;
                prev=nums[j];
            }
            minc=max(minc, inc);
        }
        int mdec=0;
        for(int i=0; i<n; i++){
            int dec=1;
            int prev=nums[i];
            for(int j=i+1; j<n; j++){
                if(nums[j]<prev){
                    dec++;
                }
                else break;
                prev=nums[j];
            }
            mdec=max(mdec, dec);
        }
        int ans;
        ans=max(mdec, minc);
        return ans;
    }
};