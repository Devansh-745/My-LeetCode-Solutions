class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m=players.size();
        int n=trainers.size();
        int match=0;
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(players[i]<=trainers[j]){
                match++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return match;
    }
};