class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==k){
            return *max_element(nums.begin(), nums.end());
        }
        unordered_map<int, int> freq;
        for(int i=0; i<n-k+1; i++){
            for(int j=i; j<i+k; j++){
                freq[nums[j]]++;
            }
        }
        int maxi=-1;
        for(auto it : freq){
            if(it.second==1) maxi=max(maxi, it.first);
        }
        return maxi;
    }
};