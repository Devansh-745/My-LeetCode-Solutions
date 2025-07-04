class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        int i=0;
        while(i<n){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(asteroids[i])){
                    st.pop(); //destroy both
                }
                else if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }
            }
            i++;
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};