class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        int sum = 0;
        const int MOD = 1e9 + 7;

        int right = n-1;

        stack<int> st;

        for(int i = 0; i < n; i++){

            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            if(!st.empty()) pse[i]=st.top();

            st.push(i);
        }

        while(st.size()){ //reuse stack
            st.pop();
        }

        for(int i = right; i>=0; i--){

            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            if(!st.empty()) nse[i]=st.top();

            st.push(i);
        }

        for(int i = 0; i < n; i++){

            int contri = (nse[i]-i)*(i-pse[i]); //right contri * left contri

            sum = (sum + (contri*1LL*arr[i])%MOD)%MOD;
        }

        return sum;
    }
};