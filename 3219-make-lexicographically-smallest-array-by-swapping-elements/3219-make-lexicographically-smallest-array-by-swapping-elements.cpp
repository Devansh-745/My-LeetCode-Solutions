class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> arr=nums;
        sort(arr.begin(), arr.end());

        int grpno=0;
        unordered_map<int, int> numtogrp;
        numtogrp[arr[0]] = grpno;

        unordered_map<int, list<int>> groupToList;
        groupToList[grpno].push_back(arr[0]); 

        for(int i=1; i<n; i++){
            if(abs(arr[i]-arr[i-1])>limit){
                grpno += 1;
            }
            numtogrp[arr[i]]=grpno;
            groupToList[grpno].push_back(arr[i]);
        }

        vector<int> result(n);
        for(int i=0; i<n; i++) {
            int num = nums[i];
            int group = numtogrp[num];
            result[i] = *groupToList[group].begin(); //use hogaya to delete kardo used element ko
            groupToList[group].pop_front();
        }

        return result;
    }
};