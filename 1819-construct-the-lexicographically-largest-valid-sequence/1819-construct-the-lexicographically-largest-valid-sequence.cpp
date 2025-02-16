class Solution {
public:
    bool solve(vector<int>& ans, vector<bool>& used, int n, int index) {
        if (index == ans.size()) {
            return true; 
        }
        
        if (ans[index] != 0) {
            return solve(ans, used, n, index + 1); 
        }
        
        for (int i = n; i >= 1; --i) {
            if (used[i]) continue;
            
            if (i == 1) {
                ans[index] = 1;
                used[1] = true;
                if (solve(ans, used, n, index + 1)) {
                    return true;
                }
                used[1] = false;
                ans[index] = 0;
            }
            else {
                if (index+i < ans.size() && ans[index+i] == 0) {
                    ans[index] = i;
                    ans[index + i] = i;
                    used[i] = true;
                    if (solve(ans, used, n, index + 1)) {
                        return true;
                    }
                    used[i] = false;
                    ans[index] = 0;
                    ans[index + i] = 0;
                }
            }
        }
        
        return false; 
    }
    
    vector<int> constructDistancedSequence(int n) {
        int len=1+(n-1)*2;
        vector<int> ans(len, 0);
        vector<bool> used(n + 1, false); 
        
        solve(ans, used, n, 0);
        
        return ans;
    }
};