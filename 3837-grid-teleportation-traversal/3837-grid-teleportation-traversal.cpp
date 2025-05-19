#define ll long long
#define vl vector<ll>
class Solution {
public:
    vector<pair<ll,ll>> del = {{-1,0},{1,0},{0,1},{0,-1}};
    
    int minMoves(vector<string>& v) {
        ll n = v.size(), m = v[0].size();
        vector<vector<pair<ll,ll>>> g(26);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                char ch = v[i][j];
                if (ch >= 'A' && ch <= 'Z') {
                    g[ch - 'A'].push_back({i, j});
                }
            }
        }

        vector<vector<ll>> vis(n, vector<ll>(m, 1e9));
        vector<bool> portalUsed(26, false); 
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;
        pq.push({0, 0, 0});
        vis[0][0] = 0;

        while (!pq.empty()) {
            auto [cd, x, y] = pq.top(); pq.pop();
            if (cd > vis[x][y]) continue;
            if (x == n-1 && y == m-1) return cd;

            for (auto d : del) {
                ll dx = x + d.first, dy = y + d.second;
                if (dx >= 0 && dx < n && dy >= 0 && dy < m && v[dx][dy] != '#') {
                    if (vis[dx][dy] > cd + 1) {
                        vis[dx][dy] = cd + 1;
                        pq.push({cd + 1, dx, dy});
                    }
                }
            }

            char ch = v[x][y];
            if (ch >= 'A' && ch <= 'Z') {
                ll id = ch - 'A';
                if (!portalUsed[id]) {
                    portalUsed[id] = true;
                    for (auto [px, py] : g[id]) {
                        if (vis[px][py] > cd) {
                            vis[px][py] = cd;
                            pq.push({cd, px, py});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
