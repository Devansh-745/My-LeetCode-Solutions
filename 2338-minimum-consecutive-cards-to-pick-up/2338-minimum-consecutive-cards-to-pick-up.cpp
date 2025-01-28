class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        vector<int>hash(1000001, -1);
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            if(hash[cards[i]]!=-1){
                ans=min(ans, i-hash[cards[i]]+1);
            }
            hash[cards[i]]=i; //track last occurence
        }
        if(ans!=INT_MAX) return ans;
        return -1;
    }
};