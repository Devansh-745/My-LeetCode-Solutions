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
        else return parent[u]=findultimateparent(parent[u]);
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
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        DisjointSet ds(n*n);
        vector<int> dr={-1, 0, 1, 0};
        vector<int> dc={0, -1, 0, 1};
        //first connecting all the nodes
        for(int row=0; row<n ; row++){
            for(int col=0; col<n ; col++){
                if(grid[row][col]==0) continue;
                for(int ind=0; ind<4; ind++){
                    int newr= row+dr[ind];
                    int newc= col+dc[ind];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int node= row*n +col;
                        int newnode= newr*n +newc; //important to convert each gridelement to a node
                        ds.unionbysize(node, newnode);
                    }
                }
            }
        }
        // now trying to get the max size by converting each 0 to 1 
        int maxisle= 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col]==1) continue;
                set<int> components;
                for(int ind=0; ind<4; ind++){
                    int newr= row+dr[ind];
                    int newc= col+dc[ind];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        components.insert(ds.findultimateparent(newr*n +newc)); //so that we dont store duplicates
                    }
                }
                int cursize=1; //including the element we just converted to 1
                for(auto it : components){
                    cursize+=ds.size[it];
                }
                maxisle=max(maxisle, cursize);
            }
        }
        // in case all are 1
        for(int i=0; i<n*n; i++){
            maxisle=max(maxisle, ds.size[ds.findultimateparent(i)]);
        }
        return maxisle;
    }
};