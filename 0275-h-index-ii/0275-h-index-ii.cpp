class Solution {
public:
    int hIndex(vector<int>& citations) {
        //applying binary search since the given array is sorted :)
        int n=citations.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(citations[mid]>=n-mid){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return n-low;
    }
};