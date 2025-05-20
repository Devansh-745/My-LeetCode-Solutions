class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anamap;
        for(auto s : strs){
            string key = s;
            sort(key.begin(), key.end());
            anamap[key].push_back(s);
        }
        vector<vector<string>> ana;
        for(auto it : anamap){
            ana.push_back(it.second);
        }
        return ana;
    }
};