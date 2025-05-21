class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        int count=1; //atleast one is required
        sort(points.begin(), points.end());
        int start=points[0][0];
        int end=points[0][1];

        for(int i=1; i<n; i++){
            int newstart=points[i][0];
            int newend=points[i][1];
            if(newstart<=end){ //overlap
                end=min(end, newend);
            }
            else{ //no overlap
                count++;
                end=newend;
            }
        }
        return count;
    }
};