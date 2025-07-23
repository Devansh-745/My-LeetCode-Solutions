class Solution {
public:
    //BITMASKING fuckin hell
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> start;

        for (auto it : startWords) {
            int mask = 0;
            for (char c : it) {
                mask |= (1 << (c - 'a'));
            }
            start.insert(mask);
        }

        int ans = 0;

        for (auto it : targetWords) {
            int mask = 0;
            for (char c : it) {
                mask |= (1 << (c - 'a'));
            }

            for (char c : it) {
                int nmask = mask ^ (1 << (c - 'a'));
                if (start.find(nmask) != start.end()) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};