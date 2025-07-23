class Solution {
public:
    int pointsfinder(string &s, string target, int gain){
        int points=0;
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char cur=s[i];
            if(!st.empty() && st.top()==target[0] && cur==target[1]){
                st.pop();
                points+=gain;
            }
            else{
                st.push(cur);
            }
        }
        //reconstruct remaining string;
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s=temp;
        return points;
    }
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        int ans=0;
        string first="ab";
        string second="ba";
        if(x>y){
            ans+=pointsfinder(s, first, x);
            ans+=pointsfinder(s, second, y);
        }
        else{
            ans+=pointsfinder(s, second, y);
            ans+=pointsfinder(s, first, x);
        }
        return ans;
    }
};