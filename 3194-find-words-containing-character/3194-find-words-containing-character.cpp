class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            string cur=words[i];
            if(cur.find(x)!=string::npos){
                ans.push_back(i);
            }
        }
        return ans;
    }
};