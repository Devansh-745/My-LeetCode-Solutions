class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int ans=1;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            maxi=max(nums[i], maxi);
            mini=min(nums[i], mini);
            if(maxi-mini>k){
                ans++;
                maxi=INT_MIN;
                mini=INT_MAX;
                i--;
            }
        }
        return ans;
    }
};