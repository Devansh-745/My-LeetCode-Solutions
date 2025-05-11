class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long m=nums1.size();
        long long n=nums2.size();
        long long sum1=accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2=accumulate(nums2.begin(), nums2.end(), 0LL);
        long long zero1=0;
        long long zero2=0;
        for(long long i=0; i<m; i++){
            if(nums1[i]==0) zero1++;
        }
        for(long long i=0; i<n; i++){
            if(nums2[i]==0) zero2++;
        }
        if(sum1>sum2 && zero2==0) return -1;
        if(sum2>sum1 && zero1==0) return -1;
        if(sum1==sum2){
            if(zero1!=0 && zero2!=0) return sum1+max(zero1, zero2);
            if(zero1==0 && zero2==0) return sum1;
        }
        if(zero1!=0 && zero2!=0){
            return max(sum1+zero1, sum2+zero2);
        }
        if(sum1+zero1>sum2+zero2 && zero2==0) return -1;
        if(sum1+zero1<sum2+zero2 && zero1==0) return -1;
        return max(sum1+zero1, sum2+zero2);
    }
};