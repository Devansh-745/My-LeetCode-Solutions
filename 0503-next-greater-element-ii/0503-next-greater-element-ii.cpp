class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> newnums=nums;
        for(int i=0; i<n; i++){
            newnums.push_back(nums[i]);
        }
        vector<int> nge(2*n);
        stack<int> st;
        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && st.top()<=newnums[i]){
                st.pop();
            }
            if(st.empty()) nge[i]=-1;
            else nge[i]=st.top();
            st.push(newnums[i]);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(nge[i]);
        }
        return ans;
    }
};