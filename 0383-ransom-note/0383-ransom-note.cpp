class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m=ransomNote.length();
        int n=magazine.length();
        if(n<m) return false;
        
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(int i=0; i<m; i++){
            freq1[ransomNote[i]-'a']++;
        }
        for(int i=0; i<n; i++){
            freq2[magazine[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq1[i]>freq2[i]) return false;
        }
        return true;
    }
};