class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms, vector<bool> &visit, int n){
        visit[i]=true;
        for(auto it : rooms[i]){
            if(!visit[it]) dfs(it, rooms, visit, n);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visit(n, false);
        dfs(0, rooms, visit, n);
        for(int i=0; i<n; i++){
            if(!visit[i]) return false;
        }
        return true;
    }
};