class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        // string copy=s;
        // reverse(copy.begin(), copy.end());
        // if(copy==s){
        //     if(n%2==0) return 0;
        //     return 1;
        // }
        int i=0;
        int j=n-1;
        while(i<j && s[i]==s[j]){
            char ch=s[i];
            while(i<=j && s[i]==ch){
                i++;
            }
            while(j>=i && s[j]==ch){
                j--;
            }
        }
        return j-i+1; //number of remaining characters
    }
};