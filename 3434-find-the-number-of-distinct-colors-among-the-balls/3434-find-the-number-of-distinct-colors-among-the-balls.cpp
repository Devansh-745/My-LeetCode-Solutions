class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls;
        unordered_map<int, int> colours;
        vector<int> ans;
        int count=0;

        for(auto query : queries){
            int ball=query[0];
            int colour=query[1];
            if(balls.count(ball)) { 
                int prev= balls[ball];
                if(--colours[prev]==0){ 
                    count--;
                    colours.erase(prev);
                }
            }
            balls[ball]=colour;
            if(++colours[colour]==1){ 
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
