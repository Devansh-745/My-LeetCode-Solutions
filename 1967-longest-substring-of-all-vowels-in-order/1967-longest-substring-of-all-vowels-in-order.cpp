class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.length();
        int maxlen=0;
        for(int i=1; i<n; i++){
            if(word[i-1]=='a'){
                int curlen=1;
                int unq=1;
                while(i<n && word[i-1]<=word[i]){
                    if(word[i-1]<word[i]) unq++;
                    curlen++;
                    i++;
                }
                if(unq==5){
                    maxlen=max(maxlen, curlen);
                }
            }
        }
        return maxlen;
    }
};