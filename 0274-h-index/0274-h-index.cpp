class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int maxcite=*max_element(citations.begin(), citations.end());
        int maxh=0;
        for(int i=0; i<=maxcite; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(citations[j]>=i){
                    count++;
                }
            }
            if(count>=i){
                maxh=max(maxh, i);
            }
        }
        return maxh;
    }
};