class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        int n=arr.size();
        int count=0; 
        int pref=0;
        //even count starts as 1 since the initial sum (0) is even
        int oddc=0, evenc=1;
        for(int i=0; i<n; i++){
            pref+=arr[i];
            // If current prefix sum is even, add the number of odd subarrays
            if(pref%2==0){
                count+=oddc;
                evenc++;
            } 
            else{
                // If current prefix sum is odd, add the number of even subarrays
                count+=evenc;
                oddc++;
            }
            count%=MOD;
        }
        return count;
    }
};