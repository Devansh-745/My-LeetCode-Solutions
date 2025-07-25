class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int countneg=0;
        int countz=0;
        int countpos=0;
        for(int i=0; i<n; i++){
            if(nums[i]<0) countneg++;
            else if(nums[i]==0) countz++;
            else countpos++;
        }
        if(countneg==n) return *max_element(nums.begin(), nums.end());
        else if(countneg<n && countz>0 && countpos==0) return 0;

        unordered_set<int> freq;
        int ans=0;
        for(int i=0; i<n; i++){
            if(freq.find(nums[i])==freq.end()){
                if(nums[i]>=0) ans+=nums[i];
            }
            freq.insert(nums[i]);
        }
        return ans;
    }
};