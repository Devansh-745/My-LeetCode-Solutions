class Solution {
public:
    //important method
    int countfinder(vector<vector<int>>& matrix, int mid, int n){
        int count=0;
        for(int i=0; i<n; i++){
            count+=upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            //checking every row to find the count using BS for effiiency
            //upper bound returns >> strictly greater
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(countfinder(matrix, mid, n)>=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};