class Solution {
public:
    bool satisfy(string s1, string s2, vector<int>& groups, int i, int j){
        if(s1.length()!=s2.length()) return false;
        if(groups[i]==groups[j]) return false;
        int hamdist=0;
        int n=s1.length();
        for(int k=0; k<n; k++){
            if(s1[k]!=s2[k]) hamdist++;
            if(hamdist>1) return false;
        }
        if(hamdist==0) return false;
        return true;
    }
    //USING CONCEPT OF LONGEST INCREASING SUBSEQUENCE (BOTTOM UP)
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int> dp(n, 1); //the longest subsequence possible at the ith index
        vector<int> prev(n, -1);
        int luns=1;
        int lunind=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(satisfy(words[i], words[j], groups, i, j)){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                        if(dp[i]>luns){
                            luns=dp[i];
                            lunind=i;
                        }
                    }
                }
            }
        }
        vector<string> ans;
        int cur=lunind;
        while(cur!=-1){
            ans.push_back(words[cur]);
            cur=prev[cur];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};