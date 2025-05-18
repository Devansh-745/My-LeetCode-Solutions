class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int len = words[0].length();
        int all = words.size();
        unordered_map<string, int> origin;
        for (int i = 0; i < all; i++) {
            origin[words[i]]++;
        }
        vector<int> ans;
        int wind = len * all;
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> cur;
            int left = i;
            int count = 0;
            for (int j = i; j <= n - len; j += len) {
                string word = s.substr(j, len);
                if (origin.count(word)) {
                    cur[word]++;
                    count++;
                    while (cur[word] > origin[word]) {
                        string left_word = s.substr(left, len);
                        cur[left_word]--;
                        left += len;
                        count--;
                    }
                    if (count == all) {
                        ans.push_back(left);
                    }
                } else {
                    cur.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        return ans;
    }
};