class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.length();
        if(n==1) return 1;
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        int maxvow=-1;
        int maxcons=-1;
        for(int i=0; i<26; i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20){
                maxvow=max(maxvow, freq[i]);
            }
            else{
                maxcons=max(maxcons, freq[i]);
            }
        }
        return maxcons+maxvow;
    }
};