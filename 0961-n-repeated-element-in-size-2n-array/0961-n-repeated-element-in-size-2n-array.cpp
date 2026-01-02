class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int m=nums.size();
        unordered_map<int, int> freq;
        for(int i=0; i<m; i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>1){
                return nums[i];
            }
        }
        return -1; //shouldnt reach here
    }
};