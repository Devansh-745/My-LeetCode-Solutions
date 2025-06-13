class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int mindiff=INT_MAX;
        for(int i=0; i<n-1; i++){
            if(nums[i+1]-nums[i]<mindiff){
                mindiff=nums[i+1]-nums[i];
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++){
            if(nums[i+1]-nums[i]==mindiff){
                ans.push_back({nums[i], nums[i+1]});
            }
        }
        return ans;
    }
};