class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m>n) return "";
        int left=0;
        int right=0;
        unordered_map<char, int> trac;
        for(int i=0; i<m; i++){
            trac[t[i]]++;
        }
        int mini=INT_MAX;
        int count=0;
        int start=-1;
        while(right<n){
            if(trac[s[right]]>0){
                count++;
            }
            trac[s[right]]--;
            while(count==m){
                if(right-left+1<mini){
                    mini=right-left+1;
                    start=left;
                }
                trac[s[left]]++;
                if(trac[s[left]]>0) count--;
                left++;
            }
            right++;
        }
        if(start!=-1) return s.substr(start, mini);
        return "";
    }
};