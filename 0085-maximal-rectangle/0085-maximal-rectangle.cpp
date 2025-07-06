class Solution {
public:
// using the exact same code of "84. Largest Rectangle in Histogram"
    void findnse(vector<int> &heights, vector<int>& nse, int n){
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
    }
    void findpse(vector<int> &heights, vector<int>& pse, int n){
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
    }
    int maxhistogram(vector<int>& heights) {
        int n=heights.size();
        if(n==1) return heights[0];
        vector<int> nse(n, -11);
        vector<int> pse(n, -11);
        findnse(heights, nse, n);
        findpse(heights, pse, n);
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            if(nse[i]==-11) nse[i]=n;
            if(pse[i]==-11) pse[i]=-1;
            ans=max(ans, heights[i]*(nse[i]-pse[i]-1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>> prefixsum(m, vector<int>(n, 0));
        for(int j=0; j<n; j++){
            int sum=0;
            for(int i=0; i<m; i++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0') sum=0;
                prefixsum[i][j]=sum;
            }
        }
        for(int i=0; i<m; i++){
            ans=max(ans, maxhistogram(prefixsum[i]));
        }
        return ans;
    }
};