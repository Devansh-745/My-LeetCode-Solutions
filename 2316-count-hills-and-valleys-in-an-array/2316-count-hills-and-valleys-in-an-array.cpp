class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        vector<int> equi;
        equi.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i-1]!=nums[i]) equi.push_back(nums[i]);
        }
        for(int i=1; i<equi.size()-1; i++){
            if(equi[i-1]<equi[i] && equi[i+1]<equi[i]) count++;
            else if(equi[i-1]>equi[i] && equi[i+1]>equi[i]) count++;
        }
        return count;
    }
};