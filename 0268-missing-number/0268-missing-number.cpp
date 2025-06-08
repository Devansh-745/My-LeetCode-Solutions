class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0;
        int xor_nums = 0;
        
        for (int i = 0; i <= n; ++i) {
            xor_all ^= i;       // XOR all numbers from 0 to n
        }
        for (int num : nums) {
            xor_nums ^= num;    // XOR all numbers in the array
        }

        return xor_all ^ xor_nums; // The missing number
    }
};
