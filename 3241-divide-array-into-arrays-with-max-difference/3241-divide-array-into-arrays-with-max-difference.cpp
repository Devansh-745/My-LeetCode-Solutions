class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<vector<int>> noans;
        
        for(int i=0; i<n-3; i+=3){
            int first=nums[i];
            int second=nums[i+1];
            int third=nums[i+2];
            if(second-first>k || third-second>k || third-first>k){
                return noans;
            }
            ans.push_back({first, second, third});
        }

        if(nums[n-2]-nums[n-3]>k || nums[n-1]-nums[n-2]>k || nums[n-1]-nums[n-3]>k){
            return noans;
        }

        ans.push_back({nums[n-3], nums[n-2], nums[n-1]});
        return ans;
    }
};