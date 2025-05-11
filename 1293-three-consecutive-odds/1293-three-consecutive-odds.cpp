class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int cons=0;
        for(int i=0; i<n; i++){
            if(arr[i]%2!=0){
                cons++;
            }
            else cons=0;
            if(cons==3){
                return true;
            }
        }
        return false;
    }
};