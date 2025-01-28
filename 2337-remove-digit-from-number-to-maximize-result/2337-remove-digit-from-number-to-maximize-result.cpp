class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int i = n-1;
        string ans = number,fans = "";
        while(i>=0){
            if(number[i] == digit){
                ans.erase(ans.begin()+i);
                if(fans<ans){fans = ans;}
                ans = number;
            }
            i--;
        }
        return fans;
    }
};