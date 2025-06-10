class Solution {
public:
    int maxDifference(string s) {
        int n=s.length();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        int maxodd=0, mineven=INT_MAX;
        for(int f:freq){
            if(f > 0){
                if(f%2 == 1){ 
                    maxodd=max(maxodd, f);
                } 
                else{ 
                    mineven=min(mineven, f);
                }
            }
        }
        if (maxodd == 0 || mineven == INT_MAX) return 0;

        return maxodd-mineven;
    }
};