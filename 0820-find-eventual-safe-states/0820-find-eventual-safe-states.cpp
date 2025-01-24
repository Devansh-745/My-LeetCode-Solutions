class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> revadj[n]; 
        vector<int> indegree(n); //all this to reverse the edges to apply KAHN'S algorithm
        for(int i=0; i<n; i++){
            for(auto it : graph[i]){
                revadj[it].push_back(i);
                indegree[i]++; //it->i
            }
        }
        //so the nodes which had outdegrees as 0 now have their indegrees to be 0
        //essentially we are backtracking from the terminal nodes to get all the safe nodes
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : revadj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};