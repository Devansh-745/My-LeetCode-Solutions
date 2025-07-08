class Solution {
public:
    int memoize(int i, int count, vector<vector<int>>& events, int k, int n, vector<vector<int>>& dp){
        if(count==k || i==n) return 0;
        if(dp[i][count]!=-1) return dp[i][count];
        int nottake=memoize(i+1, count, events, k, n, dp);

        //while (j<n && events[j][0]<=events[i][1]) j++; // find next non-overlapping (tle)

        int low=i+1;
        int high=n-1;
        int j=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(events[mid][0]>events[i][1]){ //non overlapping
                j=mid; 
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        int take=INT_MIN;
        if(j!=-1) take=events[i][2] + memoize(j, count+1, events, k, n, dp);
        else take=events[i][2] + memoize(n, count+1, events, k, n, dp); //last index u can take 

        return dp[i][count]=max(take, nottake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(), events.end()); // sort by start day
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return memoize(0, 0, events, k, n, dp);
    }
};
