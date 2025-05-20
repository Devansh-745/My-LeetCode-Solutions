class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int total=queries.size();
        vector<int> diff(n, 0);
        for(int i=0; i<total; i++){
            int start=queries[i][0];
            int end=queries[i][1];
            diff[start]+=1;
            if(end+1<n) diff[end+1]-=1;
        }
        int cumsum=0;
        for(int i=0; i<n; i++){
            cumsum+=diff[i];
            diff[i]=cumsum;
            if(nums[i]-diff[i]>0){
                return false;
            }
        }
        return true;
    }
};