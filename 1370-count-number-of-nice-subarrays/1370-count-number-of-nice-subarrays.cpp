class Solution {
public:
    int binarysubarray(vector<int>& nums, int k, int n){
        if(k<0) return 0;
        int i=0;
        int j=0;
        int sum=0;
        int total=0;
        while(j<n){
            sum+=nums[j];
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            total+=(j-i+1);
            j++;
        }
        return total;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(); 
        //convert odds and evens to 1 & 0 to make it binary data
        for(int i=0; i<n; i++){
            if(nums[i]%2==0) nums[i]=0; //even
            else nums[i]=1; //odd
        }
        return binarysubarray(nums, k, n) - binarysubarray(nums, k-1, n);
    }
};