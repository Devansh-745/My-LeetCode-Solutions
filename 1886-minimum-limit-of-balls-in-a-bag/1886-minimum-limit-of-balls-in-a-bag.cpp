class Solution {
public:
    bool possible(vector<int>& nums, int mid, int maxo, int n){
        long long count=0;
        for(int i=0; i<n; i++){
            if(nums[i]>=mid) count+=(nums[i]-1)/mid;
        }
        if(count>maxo) return false;
        return true;
    }
    int minimumSize(vector<int>& nums, int maxo) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums, mid, maxo, n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};