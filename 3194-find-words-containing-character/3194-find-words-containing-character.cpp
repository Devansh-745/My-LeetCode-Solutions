class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            string cur=words[i];
            for(int j=0; j<cur.length(); j++){
                if(cur[j]==x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};