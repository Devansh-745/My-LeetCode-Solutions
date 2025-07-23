class Solution {
public:
// next smaller element question
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(st.empty()) nse[i]=-1;
            else nse[i]=st.top();
            st.push(prices[i]);
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(nse[i]==-1) ans[i]=prices[i];
            else ans[i]=prices[i]-nse[i];
        }
        return ans;
    }
};