class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        if(n==0) return ans; 

        int prev=nums[0];
        string cur=to_string(nums[0]);
        
        for(int i=1; i<n; i++){
            if(nums[i-1]==nums[i]-1){
                continue;
            } 
            else{
                if(prev!=nums[i-1]){
                    cur += "->" + to_string(nums[i-1]);
                }
                ans.push_back(cur);
                
                prev=nums[i];
                cur=to_string(prev);
            }
        }
        
        // Add the last range
        if(prev!=nums.back()){
            cur += "->" + to_string(nums.back());
        }
        ans.push_back(cur);
        
        return ans;
    }
};