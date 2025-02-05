class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n!=m) return false;
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for(int i=0; i<n; i++){
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(hash1[i]!=hash2[i]) return false;
        }
        int count=0;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]) count++;
        }
        if(count>2) return false;
        return true;
    }
};