class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string> ans;
        int i=0;
        while(i<n){
            string cur="";
            int count=0;
            while(count<k && i<n){
                cur+=s[i];
                count++;
                i++;
            }
            while(cur.size()<k){
                cur+=fill;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};