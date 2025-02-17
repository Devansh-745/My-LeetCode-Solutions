class Solution {
public:
    void solver(unordered_set<string> &store, vector<bool>& used, string sub, string& tiles, int n){
        store.insert(sub);
        for(int i=0; i<n; i++){
            if(used[i]) continue;
            used[i]=true;
            sub.push_back(tiles[i]);
            solver(store, used, sub, tiles, n);
            used[i]=false;
            sub.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        vector<bool> used(n, false);
        unordered_set<string> store;
        string sub="";
        solver(store, used, sub, tiles, n);
        return store.size()-1; //remove empty sequence
    }
};