class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> distinct(nums.size()+1, 0);
        int totalcount=0;
        int left=0;
        int right=0;
        int curcount=0;

        while(right < nums.size()){
            if(++distinct[nums[right++]]==1)  k--; //if new element found
            if(k<0){
                --distinct[nums[left++]];
                k++;
                curcount = 0;
            }
            //if k becomes zero, calculate subarrays
            if(k==0){
                while(distinct[nums[left]]>1){
                    --distinct[nums[left++]];
                    curcount++;
                }
                totalcount+=(curcount+1);
            }
        }
        return totalcount;
    }
};