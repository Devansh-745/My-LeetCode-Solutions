class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> lastseen; 
        for(int i=0; i<n; i++){
            if(lastseen.count(nums[i])){
                if(abs(i-lastseen[nums[i]])<=k){
                    return true;
                }
            }
            lastseen[nums[i]]=i;
        }
        return false;
    }
};