class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    typedef pair<int, pair<int, int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        // Priority queue: {time, {i, j}, nextMoveTime}
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq; 
        
        result[0][0] = 0;
        pq.push({0, 0, 0, 1}); // {time, i, j, nextMoveTime}

        while(!pq.empty()) { 
            auto [currTime, i, j, nextMove] = pq.top();
            pq.pop();

            if(i == m-1 && j == n-1) {
                return currTime;
            }

            for(auto &dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    int wait = max(moveTime[i_][j_] - currTime, 0);
                    int arrTime = currTime + wait + nextMove;
                    
                    if(arrTime < result[i_][j_]) {
                        result[i_][j_] = arrTime;
                        // Alternate between 1 and 2 for the next move
                        int nextMoveTime = nextMove == 1 ? 2 : 1;
                        pq.push({arrTime, i_, j_, nextMoveTime});
                    }
                }
            }
        }

        return -1;
    }
};