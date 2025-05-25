class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        int pairs = 0;
        bool has_middle = false;

        for (auto& [word, count] : freq) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                pairs += count / 2;  // Pairs of "oo", "vv", etc.
                if (count % 2 == 1) has_middle = true;
            } 
            else if (word < rev && freq.count(rev)) {  // Avoid double-counting
                pairs += min(count, freq[rev]);  // Pairs like "ab"+"ba"
            }
        }

        return 4 * pairs + (has_middle ? 2 : 0);
    }
};