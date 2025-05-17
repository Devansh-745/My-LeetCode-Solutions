class Solution {
public:
    //DUTCH NATIONAL FLAG ALGORITHM BASED ON QUICKSORT
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(nums[mid]==2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
        }
        return;
    }
};