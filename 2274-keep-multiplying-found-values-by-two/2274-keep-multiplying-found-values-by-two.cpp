class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        int to_find=original;
        while(freq.find(to_find)!=freq.end()){
            to_find*=2;
        }
        return to_find;
    }
};