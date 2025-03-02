class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2){
        int m=nums1.size();
        int n=nums2.size();
        int p1=0;
        int p2=0;
        vector<vector<int>> ans;
        while(p1<m && p2<n){
            if(nums1[p1][0]<nums2[p2][0]){
                ans.push_back(nums1[p1]);
                p1++;
            }
            else if(nums1[p1][0]>nums2[p2][0]){
                ans.push_back(nums2[p2]);
                p2++;
            }
            else{
                vector<int> np;
                np.push_back(nums1[p1][0]);
                np.push_back(nums1[p1][1]+nums2[p2][1]);
                ans.push_back(np);
                p1++;
                p2++;
            }
        }
        while(p1<m){
            ans.push_back(nums1[p1]);
            p1++;
        } 
        while(p2<n){
            ans.push_back(nums2[p2]);
            p2++;
        }
        return ans;
    }
};