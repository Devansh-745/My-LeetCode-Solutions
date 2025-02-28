class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1= str1.length();
        int n2= str2.length();
        string trac="";
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        //fill the dp table first using the method to find the lcs
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);;
            }
        }

        int i=n1;
        int j=n2;
        //traverse the dp table to obtain the answer
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                trac+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1]){
                trac+=str1[i-1];
                i--;
            }
            else if(dp[i-1][j]<dp[i][j-1]){
                trac+=str2[j-1];
                j--;
            }
        }
         // Add remaining characters from str1
        while(i>0) {
            trac+= str1[i - 1];
            i--;
        }

        // Add remaining characters from str2
        while(j>0) {
            trac+= str2[j - 1];
            j--;
        }

        string scss=trac;
        reverse(scss.begin(), scss.end());
        return scss;
    }
};