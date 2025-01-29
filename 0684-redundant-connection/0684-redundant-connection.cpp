class DisjointSet{
    public: 
    vector<int> rank, size, parent;
    
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findultimateparent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findultimateparent(parent[u]);
    }
    void unionbyrank(int u, int v){
        int ultu= findultimateparent(u);
        int ultv= findultimateparent(v);
        if(ultu==ultv) return;
        else if(rank[ultu]<rank[ultv]){
            parent[ultu]=ultv;
        }
        else if(rank[ultu]>rank[ultv]){
            parent[ultv]=ultu;
        }
        else{
            parent[ultv]=ultu;
            rank[ultu]++;
        }
    }
    void unionbysize(int u, int v){
        int ultu= findultimateparent(u);
        int ultv= findultimateparent(v);
        if(ultu==ultv) return;
        else if(size[ultu]<size[ultv]){
            parent[ultu]=ultv;
            size[ultv]+=size[ultu];
        }
        else{
            parent[ultv]=ultu;
            size[ultu]+=size[ultv];
        }
    } 
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int v=edges.size();
        DisjointSet dsu(v);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            if(dsu.findultimateparent(u) == dsu.findultimateparent(v)){
                return it;  
            }
            dsu.unionbyrank(u, v);
        }
        return {}; //dummy output, code wont reach here
    }
};