class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int> st;
        int ans=0;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && height[st.top()]<height[i]){
                int top=st.top();
                st.pop();
                if(st.empty()) break;
                
                int ind=st.top();

                ans+=(min(height[i], height[ind])-height[top])*(ind-i-1);
            }
            st.push(i);
        }
        return ans;
    }
};