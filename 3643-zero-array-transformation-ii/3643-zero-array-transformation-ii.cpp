class Solution {
public:
    bool diffarray(vector<int>& nums, vector<vector<int>>& queries, int mid){
        int n=nums.size();
        vector<long long> diff(n, 0);
        for(int i=0; i<=mid; i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int delta=queries[i][2];
            diff[start]+=delta;
            if(end+1<n) diff[end+1]-=delta;
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
    long long minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long n=nums.size();
        long long m=queries.size();
        long long low=0;
        long long high=m-1;
        if(accumulate(nums.begin(), nums.end(), 0LL)==0) return 0;
        long long ans=LLONG_MAX;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(diffarray(nums, queries, mid)){
                high=mid-1;
                ans=min(ans, mid+1);
            }
            else{
                low=mid+1;
            }
        }
        if(ans==LLONG_MAX) return -1;
        return ans;
    }
};