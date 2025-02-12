class Solution {
public:
    int digi(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>>sum(n);
        for(int i=0; i<n; i++){
            sum[i].first=digi(nums[i]);
            sum[i].second=nums[i];
        }
        sort(sum.rbegin(), sum.rend());
        int maxx=-1;
        for(int i=1; i<n; i++){
            int count=0;
            if(sum[i-1].first==sum[i].first){
                count=sum[i-1].second+sum[i].second;
                maxx=max(maxx, count);
            }
        }
        return maxx;
    }
};