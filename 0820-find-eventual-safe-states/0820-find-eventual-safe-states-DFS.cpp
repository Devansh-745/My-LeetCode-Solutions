class Solution {
public:
    //using DFS
    bool dfs(int node, vector<bool>& vis, vector<bool>& pathvis, vector<int>& count, vector<vector<int>>& graph){
        vis[node]=true;
        pathvis[node]=true;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathvis, count, graph)==true){
                    // count[node]=0;
                    return true;
                }
            }
            else if(vis[it] && pathvis[it]){
                // count[node]=0;
                return true;
            }
        }
        count[node]=1; //means its a safe node as no cycle has been detected
        pathvis[node]=false; //reset path
        return false; //no cycle detected
    }
    //dfs returning true means detection of cycle
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<bool> vis(n, false);
        vector<bool> pathvis(n, false); 
        vector<int> count(n, 0); // to keep track of safe nodes

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, pathvis, count, graph);
            }
        }
        vector<int> ans; 
        for(int i=0; i<n; i++){
            if(count[i]==1) ans.push_back(i);
        } // this way it is automatically sorted
        return ans;      
    }
};
