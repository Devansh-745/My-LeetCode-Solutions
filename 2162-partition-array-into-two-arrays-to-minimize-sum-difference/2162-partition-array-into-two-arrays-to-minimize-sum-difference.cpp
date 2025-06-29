class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0); // Calculate total sum of the array
        
        int N = n / 2;
        vector<vector<int>> left(N + 1), right(N + 1);
        
        // Storing all possible subset sums in left and right parts
        for (int mask = 0; mask < (1 << N); ++mask) {
            int sz = 0, l = 0, r = 0;
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) { // Checking if the i-th bit is set
                    sz++;
                    l += nums[i];      // Sum for left subset
                    r += nums[i + N];  // Sum for right subset
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        // Sorting right subsets for binary search optimization
        for (int sz = 0; sz <= N; ++sz) {
            sort(right[sz].begin(), right[sz].end());
        }

        // Initializing res with the min possible difference using full left/right subsets
        res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

        // Iterating over left part subsets (starting from size 1, not 0)
        for (int sz = 1; sz < N; ++sz) {
            for (auto &a : left[sz]) {
                int b = (sum - 2 * a) / 2, rsz = N - sz;
                auto &v = right[rsz];

                // Binary search to find closest value to 'b' in the right subset
                auto itr = lower_bound(v.begin(), v.end(), b);
                
                // If a valid element is found in right subset, update res
                if (itr != v.end()) res = min(res, abs(sum - 2 * (a + (*itr))));
                
                // If not at the beginning, check the previous element for a better min difference
                if (itr != v.begin()) {
                    auto it = itr; --it;
                    res = min(res, abs(sum - 2 * (a + (*it))));
                }                
            }
        }
        return res;
    }
};