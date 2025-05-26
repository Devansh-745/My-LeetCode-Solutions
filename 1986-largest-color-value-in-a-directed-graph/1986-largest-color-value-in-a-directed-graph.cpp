class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        int m=edges.size();
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for(int i=0; i<m; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            indeg[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        //vector<int> topo;
        for(int i=0; i<n; i++){
            if(indeg[i]==0){
                q.push(i);
                //topo.push_back(i);
            }
        }
        vector<vector<int>> colorcount(n, vector<int>(26, 0));
        int count=0;
        int maxc=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            count++;

            colorcount[cur][colors[cur]-'a']++;
            maxc=max(maxc, colorcount[cur][colors[cur]-'a']);

            for(auto it : adj[cur]){
                indeg[it]--;
                for(int i=0; i<26; i++){
                    colorcount[it][i]=max(colorcount[it][i], colorcount[cur][i]);
                }
                if(indeg[it]==0){
                    q.push(it);
                    //topo.push_back(it);
                }
            }
        }
        if(count!=n) return -1; //all nodes not reached, ie. a cycle is detected

        return maxc;
    }
};