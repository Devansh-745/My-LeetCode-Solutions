class Solution {
public:
    bool repairer(vector<int>& ranks, int cars, long long mid) {
        long long count = 0;
        int n = ranks.size();
        for (int i = 0; i < n; i++) {
            long long c2 = mid / ranks[i];
            count += (c2 > 0) ? (long long)sqrtl(c2) : 0;  // Ensure sqrtl() is never called on negative values
        }
        return count >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars;
        long long ans = LLONG_MAX;

        while (low <= high) {
            long long mid = low + (high - low) / 2;  // Ensure mid is long long
            if (repairer(ranks, cars, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
