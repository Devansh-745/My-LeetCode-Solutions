class Solution {
public:
    bool check(int i, int currsum, string s, int num, vector<vector<int>>& dp){
        if(i==s.length()) return currsum==num;
        if(currsum>num) return false;

        if(dp[i][currsum]!=-1) return dp[i][currsum];

        bool possible=false;
        for(int j=i; j<s.length(); j++){
            string curs=s.substr(i, j-i+1);
            int addend=stoi(curs);

            possible = possible || check(j+1, currsum+addend, s, num, dp);
            if(possible==true) return true;
        }
        return dp[i][currsum]=possible;
    }

    int punishmentNumber(int n){
        int punish=0;
        for (int num = 1; num <= n; num++) {
            int squ=num*num;
            string s = to_string(squ);

            vector<vector<int>> dp(s.size(), vector<int>(num+1, -1));

            if (check(0, 0, s, num, dp)) {
                punish+=squ;
            }
        }
        return punish;
    }
};