class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;     //if there are some k remaining
        }
        if(st.empty()) return "0"; //if k==n
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        string ans="";
        int j;
        for(int i=0; i<res.length(); i++){
            if(res[i]!='0'){
                j=i;
                break;
            }
        }
        for(int i=j; i<res.length(); i++){
            ans+=res[i];
        }
        if(ans=="") return "0";
        return ans;
    }
};