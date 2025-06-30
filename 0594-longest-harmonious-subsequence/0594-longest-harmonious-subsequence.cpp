class Solution {
public:
    int findLHS(vector<int>& nums){
        int n=nums.size();
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        int maxlen=0;
        for(auto& [num, count] : freq){
            if(freq.count(num+1)){
                maxlen=max(maxlen, count+freq[num+1]);
            }
        }
        return maxlen;
    }
};
