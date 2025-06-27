class Solution {
public:
    //THOUGHT PROCESS---
    /*
    
    1. first remove all the characters whose frequency is less than k and create a new string "newstring", devoid of them.
    2. next, store the required freq of each eligible character in a vector (denotes the max. number of times these chars 
       can occur in the subsequence) + find the maxlen which is the max. length possible, which will create a threshold 
       ie. our subsequence cannot literally be longer than this value.
    3. now, we will run a backtracking algo to give us all possible subsequences using the characters we just filtered.
        we will run this algo for each length starting from longest maxlen to be more efficient.
    4. then, once we generate a possible subsequence we will check whether it can actually satisfy the condition ie. 
        check whether "k-times appended string" actually is a subsequence of the "newstring".
    5. if yes, then we store our answer in result, if not then we try again with some other combination or a smaller 
       length.


    */
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