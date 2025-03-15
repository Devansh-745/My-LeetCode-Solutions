class Solution {
public:
    bool capchecker(vector<int>& nums, int k, int mid){
        int count=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<=mid){  
                count++; 
                i++;     //skip adjacent house
            }
        }
        return count>=k; //if we can rob atleast k houses
    }

    int minCapability(vector<int>& nums, int k) {
        int low=*min_element(nums.begin(), nums.end()); 
        int high=*max_element(nums.begin(), nums.end());
        int ans=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(capchecker(nums, k, mid)){
                ans=min(ans, mid);
                high=mid-1; 
            } 
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
