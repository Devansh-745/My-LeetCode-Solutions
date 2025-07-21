class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length();
        int m=t.length();
        string news="";
        for(int i=0; i<n; i++){
            if(s[i]!='#') news+=s[i];
            else{
                if(!news.empty()) news.pop_back();
            }
        }
        string newt="";
        for(int i=0; i<m; i++){
            if(t[i]!='#') newt+=t[i];
            else{
                if(!newt.empty()) newt.pop_back();
            }
        }
        if(news==newt) return true;
        return false;
    }
};