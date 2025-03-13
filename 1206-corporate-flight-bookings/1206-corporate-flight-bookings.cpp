class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        for(int i=0; i<bookings.size(); i++){
            int start=bookings[i][0];
            int end=bookings[i][1];
            int delta=bookings[i][2];
            
            diff[start-1]+=delta;
            if(end<n) diff[end]-=delta; //converted to 1-based indexing
        }
        int cumsum=0;
        for(int i=0; i<n; i++){
            cumsum+=diff[i];
            diff[i]=cumsum;
        }
        return diff;
    }
};