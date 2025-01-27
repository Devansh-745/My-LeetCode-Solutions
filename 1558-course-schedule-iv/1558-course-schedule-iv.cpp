class Solution {
public:
//KAHN'S ALGO TOPO SORT
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        vector<int> indegree(n, 0);
        vector<vector<int>> edges(n);
        for(int i=0; i<prereq.size(); i++){
            int u=prereq[i][0];
            int v=prereq[i][1];
            edges[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<vector<bool>> ispre(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto it : edges[cur]){
                ispre[cur][it] = true; //mark direct prerequisite
                //mark indirect prerequisites
                for(int i=0; i<n; i++){
                    if(ispre[i][cur]){
                        ispre[i][it]=true;
                    }
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            int u=queries[i][0];
            int v=queries[i][1];
            ans.push_back(ispre[u][v]);
        }
        return ans;
    }
};