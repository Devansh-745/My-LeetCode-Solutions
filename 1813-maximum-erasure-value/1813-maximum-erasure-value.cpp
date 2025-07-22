class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> tracker;
        int ans=0;
        int maxi=0;
        int i=0;
        int j=0;
        while(i<=j && j<n){
            if(tracker.find(nums[j])==tracker.end()){
                maxi+=nums[j];
                tracker.insert(nums[j]);
                ans=max(maxi, ans);
                j++;
            }
            else{
                tracker.erase(nums[i]);
                maxi-=nums[i];
                i++;
            }
        }
        return ans;
    }
};