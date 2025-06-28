class Solution {
public:

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int, int>>copy(n);
        for(int i=0; i<n; i++){
            copy[i]={nums[i], i};
        }
        sort(copy.rbegin(), copy.rend());
        vector<pair<int,int>> temp;
        for(int i=0; i<k; i++){
            temp.push_back({copy[i].second, copy[i].first});
        }
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for(int i=0; i<temp.size(); i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};