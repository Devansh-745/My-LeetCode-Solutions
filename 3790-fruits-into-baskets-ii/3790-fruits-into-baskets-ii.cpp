class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool> used(n, false);
        vector<bool> placed(n, false);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(fruits[i]<=baskets[j] && !used[j] && !placed[i]){
                    used[j]=true;
                    placed[i]=true;
                    break;
                }
            }
        }
        int un=0;
        for(int i=0; i<n; i++){
            if(!placed[i]) un++;
        }
        return un;
    }
};