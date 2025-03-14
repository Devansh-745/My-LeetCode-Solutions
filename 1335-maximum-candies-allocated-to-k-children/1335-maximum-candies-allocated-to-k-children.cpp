class Solution {
public:
    bool candylelo(vector<int> &candies, long long k, long long mid){
        long long count=0;
        for(int i=0; i<candies.size(); i++){
            count+=candies[i]/mid;
            if(count>=k){
                return true;
            }
        }
        return count>=k;
    }
    long long maximumCandies(vector<int>& candies, long long k) {
        long long n=candies.size();
        sort(candies.begin(), candies.end());
        long long high=candies[n-1];
        long long low=1;
        long long ans=LLONG_MIN;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(candylelo(candies, k, mid)){
                ans=max(ans, mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};