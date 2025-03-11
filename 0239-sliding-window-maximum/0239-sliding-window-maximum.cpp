class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int, int>> pq;  //Max heap: {value, index}
        vector<int> ans;
        int right=0;
        while(right<n){
            pq.push({nums[right], right});
            if(right>=k-1){
                while(!pq.empty() && pq.top().second<right-k+1){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
            right++;
        }
        return ans;
    }
};
