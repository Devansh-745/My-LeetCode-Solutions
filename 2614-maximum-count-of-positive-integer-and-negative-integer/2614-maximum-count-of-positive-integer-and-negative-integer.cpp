class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=nums.end()-upper_bound(nums.begin(), nums.end(), 0); 
        //returns the first index where the value is strictly greater than zero
        int neg=lower_bound(nums.begin(), nums.end(), 0)-nums.begin(); 
        //returns the first index where the value is greater than or equal to zero

        return max(pos, neg);
    }
};