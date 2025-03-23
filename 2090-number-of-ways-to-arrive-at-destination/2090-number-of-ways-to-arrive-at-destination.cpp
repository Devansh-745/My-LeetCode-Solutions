const int MOD = 1e9 + 7;  
class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long, long>>adj[n];
        for(int i =0; i<roads.size(); i++){
            long long u= roads[i][0];
            long long v= roads[i][1];
            long long t= roads[i][2];
            adj[v].push_back({u, t});
            adj[u].push_back({v, t});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0}); //dist, node
        vector<long long> dijktime(n, LLONG_MAX);
        dijktime[0]=0;
        vector<long long>ways(n, 0);
        ways[0]=1;
        while(!pq.empty()){
            long long curnode= pq.top().second;
            long long curtime= pq.top().first;
            pq.pop();
            for(auto it : adj[curnode]){
                long long nextnode= it.first;
                long long edgetime= it.second;
                if(dijktime[nextnode]>curtime+edgetime){
                    dijktime[nextnode]= curtime+edgetime;
                    pq.push({dijktime[nextnode], nextnode});
                    ways[nextnode]=ways[curnode];
                }
                else if(dijktime[nextnode]==curtime+edgetime){
                    ways[nextnode]=(ways[nextnode]+ways[curnode])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};