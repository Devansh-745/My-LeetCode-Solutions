class Solution {
public:
    bool valid(vector<int>& nums, int mid, int p, int n){
        int count=0;
        for(int i=0; i<n-1;){
            if(nums[i+1]-nums[i]<=mid){
                count++;
                i+=2; //cannot take duplicates
            }
            else i++;
        }
        if(count>=p) return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int low=0;
        int high=nums[n-1]-nums[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(nums, mid, p, n)){
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