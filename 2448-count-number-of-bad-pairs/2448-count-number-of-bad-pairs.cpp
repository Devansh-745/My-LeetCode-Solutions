class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        map<int, int> mpp;
        long long count=0;
        for(int i=0; i<n; i++){
            int diff=i-nums[i];
            int good=mpp[diff];
            count+=i-good;
            mpp[diff]=good+1;
        }
        return count;
    }
};