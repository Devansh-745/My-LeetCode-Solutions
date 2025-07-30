class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size();
        int maxi= *max_element(nums.begin(), nums.end());
        int longest=0;
        int maxlength=0;
        for(int i=0; i<n; i++){
            if(nums[i]==maxi){
                longest++;
                maxlength=max(longest, maxlength);
            }
            else{
                longest=0;
            }
        }
        return maxlength;
    }
};