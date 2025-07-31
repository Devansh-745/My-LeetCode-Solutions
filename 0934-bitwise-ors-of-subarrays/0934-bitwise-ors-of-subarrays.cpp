class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result, prev;
        for (int num : arr) {
            unordered_set<int> curr;
            curr.insert(num);
            for (int x : prev) {
                curr.insert(x | num);
            }
            prev = curr;
            result.insert(curr.begin(), curr.end());
        }
        return result.size();
    }
};
