class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            int cursum=nums[i];
            int prev=nums[i];
            for(int j=i+1; j<n; j++){
                if(nums[j]>prev){
                    cursum+=nums[j];
                }
                else break;
                prev=nums[j];
            }
            maxi=max(maxi, cursum);
        }
        return maxi;
    }
};