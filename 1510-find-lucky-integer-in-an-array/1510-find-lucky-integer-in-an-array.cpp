class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
        }
        int ans=-1;
        for(int i=0; i<n; i++){
            if(arr[i]==freq[arr[i]]){
                ans=max(ans, arr[i]);
            }
        }
        return ans;
    }
};