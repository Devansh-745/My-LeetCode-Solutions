class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> remfreq;
        int cumsum=0;
        remfreq[0]=1;
        int count=0;
        for(int i=0; i<n; i++){
            cumsum+=nums[i];
            int rem=cumsum%k;
            if(rem<0) rem+=k;
            if(remfreq.find(rem)!=remfreq.end()){
                count+=remfreq[rem];
            }
            remfreq[rem]++;
        }
        return count;
    }
};