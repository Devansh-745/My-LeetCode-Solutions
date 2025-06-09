class Solution {
public:
//KADANE'S ALGORITHM
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        int currentSum=nums[0];

        for(int i=1; i<n; i++) {
            currentSum = max(nums[i], currentSum+nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};
//for printing the max subarray
/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxSum = nums[0];
        int currentSum = nums[0];
        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < n; i++) {
            if (currentSum + nums[i] < nums[i]) {
                currentSum = nums[i];
                tempStart = i;
            } else {
                currentSum += nums[i];
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }

        // Print the maximum subarray
        cout << "Maximum Subarray: ";
        for (int i = start; i <= end; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;

        return maxSum;
    }
};
*/

