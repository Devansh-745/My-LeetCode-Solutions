#define MOD 1000000007
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int ans=0;

        // Precompute powers of 2 up to n
        vector<int> powerOf2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            powerOf2[i] = (powerOf2[i - 1] * 2LL) % MOD;
        }

        for(int i=0; i<n; i++){
            int mini=nums[i];
            int j1=-1;
            // for(int j=n-1; j>=i; j--){
            //     int maxi=nums[j];
            //     if(maxi+mini<=target){
            //         j1=j;
            //         break;
            //     }
            // }
            int low=i;
            int high=n-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(nums[mid]+mini<=target){
                    j1=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            if(j1!=-1 && j1>=i){
                int len=j1-i;
                ans=(ans+powerOf2[len])%MOD;
            }
        }
        return ans;
    }
};