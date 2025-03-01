class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i+1<n; i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]*=0;
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
        }
        int rem=n-ans.size();
        for(int i=0; i<rem; i++){
            ans.push_back(0);
        }
        return ans;
    }
};