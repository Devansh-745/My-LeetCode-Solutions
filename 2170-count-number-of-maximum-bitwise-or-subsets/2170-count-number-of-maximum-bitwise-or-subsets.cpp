class Solution {
public:
    int counter(vector<int>& nums, int i, int cur, int target, int n) {
        if(i==n){
            if(cur==target) return 1;
            else return 0;
        }
        int nottake=counter(nums, i+1, cur, target, n);
        int take=counter(nums, i+1, cur|nums[i], target, n);
        return take+nottake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0; i<n; i++){
            maxi|=nums[i];
        }
        return counter(nums, 0, 0, maxi, n);
    }



};