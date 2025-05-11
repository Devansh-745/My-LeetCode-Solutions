class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> arr(n+1, 0);
        for(int i=0; i<n; i++){
            if(citations[i]>n) arr[n]++;
            else arr[citations[i]]++;
        }
        int count=0;
        for(int i=n; i>=0; i--){
            count+=arr[i];
            if(count>=i){
                return i;
            }
        }
        return 69;
    }
};