class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // No need to process if size is 2 or less
        
        int k = 2; // Start from the third element
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};