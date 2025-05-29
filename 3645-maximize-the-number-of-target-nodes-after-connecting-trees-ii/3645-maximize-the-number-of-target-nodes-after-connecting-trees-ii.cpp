class Solution {
public:
    void bfs(int cur, vector<vector<int>> &adj, vector<int> &mark, int n){
        vector<bool> visit(n, false);
        visit[0]=true;
        queue<int> q;
        q.push(0);
        mark[0]=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(auto it : adj[top]){
                if(!visit[it]){
                    visit[it]=true;
                    if(mark[top]==0) mark[it]=1;
                    else mark[it]=0;
                    q.push(it);
                }
            }
        }
        return;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();
        int m=edges2.size();
        vector<vector<int>> adj1(n+1);
        for(int i=0; i<n; i++){
            int u=edges1[i][0];
            int v=edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        vector<vector<int>> adj2(m+1);
        for(int i=0; i<m; i++){
            int u=edges2[i][0];
            int v=edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int> mark1(n+1, -1);
        mark1[0]=0;
        int zeroc=0;
        int onec=0;
        bfs(0, adj1, mark1, n+1);
        for(int i=0; i<mark1.size(); i++){
            if(mark1[i]==0) zeroc++;
            else onec++;
        }

        vector<int> mark2(m+1, -1);
        mark2[0]=0;
        int x=0;
        int y=0;
        bfs(0, adj2, mark2, m+1);
        for(int i=0; i<mark2.size(); i++){
            if(mark2[i]==0) x++;
            else y++;
        }
        int maxplus=max(x, y);

        vector<int> result=mark1;
        for(int i=0; i<result.size(); i++){
            if(result[i]==0) result[i]=zeroc+maxplus;
            else result[i]=onec+maxplus;
        }

        return result;
    }
};