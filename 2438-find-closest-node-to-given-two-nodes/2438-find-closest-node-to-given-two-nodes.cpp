class Solution {
public:
    void bfs(vector<vector<int>> &adj, int node, vector<int>&dist, int n){
        vector<bool> visit(n, false);
        visit[node]=true;
        queue<int> q;
        q.push(node);
        dist[node]=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();

            for(auto it : adj[cur]){
                if(!visit[it]){
                    visit[it]=true;
                    dist[it]=dist[cur]+1;
                    q.push(it);
                }
            }
        }
        return;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            int u=i;
            int v=edges[i];
            if(v!=-1) adj[u].push_back(v);
        }
        vector<int> dist1(n, -1);
        bfs(adj, node1, dist1, n);
        vector<int> dist2(n, -1);
        bfs(adj, node2, dist2, n);

        int minmaxi=INT_MAX;
        int ans=-1;
        for(int i=0; i<n; i++){
            if(dist1[i]==-1 || dist2[i]==-1) continue;
            int curmax=max(dist1[i], dist2[i]);
            if(curmax<minmaxi){
                minmaxi=curmax;
                ans=i;
            }
            else if(curmax==minmaxi){
                if(i<ans) ans=i;
            }
        }
        return ans;
    }
};