class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        int left=0;
        int right=0;
        unordered_map<char,int>mpp;
        while(right<n){
            mpp[s[right]]++;
            while(mpp.size()==3){
                cnt+=n-right;
                mpp[s[left]]--;
                if(mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        return cnt;
    }
};