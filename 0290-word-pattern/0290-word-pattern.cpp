class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int len=pattern.length();
        vector<string> store;
        stringstream ss(s);
        string word;
        int count=0;
        while(ss >> word){
            store.push_back(word);
            count++;
        }
        if(count!=len) return false;
        unordered_map<char, string> dict;
        unordered_map<string, char> revdict;
        for(int i=0; i<len; i++){
            if(!dict.count(pattern[i])){
                if(!revdict.count(store[i])){
                    dict[pattern[i]]=store[i];
                    revdict[store[i]]=pattern[i];
                }
                else return false;
            }
            else{
                if(dict[pattern[i]]!=store[i]){
                    return false;
                }
                if(revdict[store[i]]!=pattern[i]){
                    return false;
                }
            }
        }
        return true;
    }
};