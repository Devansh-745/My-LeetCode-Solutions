class Solution {
public:
    #define M 1000000007
    int lengthAfterTransformations(string s, int t) {
        int n=s.length();
        int curlen=0;
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        for(int i=0; i<t; i++){
            vector<int> temp(26, 0);
            for(int j=0; j<26; j++){
                if(j!=25){
                    temp[j+1]=(temp[j+1]+freq[j])%M;
                }
                else{
                    temp[0]=(temp[0]+freq[25])%M;
                    temp[1]=(temp[1]+freq[25])%M;
                }
            }
            freq=temp;
        }
        for(int i=0; i<26; i++){
            curlen=(curlen+freq[i])%M;
        }
        return curlen;
    }
};