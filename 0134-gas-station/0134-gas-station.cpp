class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gassum=accumulate(gas.begin(), gas.end(), 0);
        int costsum=accumulate(cost.begin(), cost.end(), 0);
        if(costsum>gassum) return -1;
        int curgas=0;
        int starti=0;
        for(int i=0; i<n; i++){
            curgas+=gas[i]-cost[i];
            if(curgas<0){
                starti=i+1;
                curgas=0;
            }
        }
        return starti;
    }
};