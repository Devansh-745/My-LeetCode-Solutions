class Solution {
public:
    bool subsequencechecker(string&s, string cur, int k, int m){
        int i=0;
        int j=0;
        int curlen=cur.length();
        while(i<m && j<curlen*k){
            if(s[i]==cur[j%curlen]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==curlen*k) return true;
        return false;
    }
    bool generator(string &cur, int len, vector<int>& freq, string& s, int m, int k, string &result){
        if(cur.length() == len){
            if(subsequencechecker(s, cur, k, m)){
                result=cur;
                return true;
            }
            return false;
        }
        for(int i=25; i>=0; i--){
            if(freq[i]==0) continue;
            char ch = i+'a';
            cur+=ch;
            freq[i]--;
            if(generator(cur, len, freq, s, m, k, result)) return true;
            cur.pop_back();
            freq[i]++;
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        if(k==1) return s;
        int n=s.length();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        string newstring="";
        for(int i=0; i<n; i++){
            if(freq[s[i]-'a']>=k) newstring+=s[i];
        }
        int m=newstring.length();
        vector<int> requiredfreq(26, 0); //atmost what freq per each character
        for(int i=0; i<26; i++){
            if(freq[i]>=k) requiredfreq[i]=freq[i]/k; //only take those who satisfy the condition, rest are 0
        }
        string result="";
        int maxlen=n/k;
        for(int len=maxlen; len>0; len--){
            string cur="";
            if(generator(cur, len, requiredfreq, newstring, m, k, result)) return result;
        }
        return result;
    }   
};