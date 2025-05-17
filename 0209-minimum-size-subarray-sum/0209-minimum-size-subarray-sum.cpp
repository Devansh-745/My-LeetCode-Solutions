class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            if(target<=nums[0]) return 1;
            return 0;
        }
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum<target) return 0;
        if(sum==target) return n;
        for(int i=0; i<n; i++){
            if(nums[i]>=target){
                return 1;
            }
        }
        int i=0;
        int j=1;
        int minlen=INT_MAX;
        int cursum=nums[0]+nums[1];
        while(i<=j && j<n){
            if(cursum<target){
                j++;
                if(j<n) cursum+=nums[j];
            }
            else{
                minlen=min(minlen, j-i+1);
                cursum-=nums[i];
                i++;
            }
        }
        if(minlen==INT_MAX) return 0;
        return minlen;
    }
};