class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> store(n); //we need to keep track of results from each component which are not neccessarily connected
        for(int i=0; i<n; i++){
            queue<int> q;
            q.push(i);
            vector<int> dist(n);
            dist[i]=1;
            int maxx=1;
            int root=i;
            while(q.size()){
                int cur=q.front();
                q.pop();
                root=min(root, cur);
                for(auto it : adj[cur]){
                    if(dist[it]==0){ //if hasnt been visited yet
                        dist[it]=dist[cur]+1; //stores depth
                        maxx=max(maxx, dist[it]); //stores max depth ever encountered during this traversal
                        q.push(it);
                    } 
                    else if(abs(dist[cur]-dist[it]) != 1){//graph not bipartite
                        return -1; //odd length cycle detected
                    }
                }
            }
            store[root] = max(store[root], maxx); //updates maximum depth for the particualar component
        }
        return accumulate(store.begin(), store.end(), 0);
    }
};