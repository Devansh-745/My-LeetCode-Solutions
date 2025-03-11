class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> copy1(n);
        for(int i=0; i<n; i++){
            copy1[i].first=nums1[i];
            copy1[i].second=i;
        }
        sort(copy1.begin(), copy1.end());
        vector<long long> ans(n);
        int j=0; //pointer to track valid elements in pq
        long long sum=0;
        priority_queue<int, vector<int>, greater<int>> pq;//Min-Heap to track largest `k` elements from nums2
        for(int i=0; i<n; i++){
            int idx=copy1[i].second;
            while(j<i){
                int prev=copy1[j].second;
                if(copy1[j].first>=copy1[i].first) break;
                pq.push(nums2[prev]);
                sum+=nums2[prev];
                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
                j++;
            }
            ans[idx]=sum;
        }
        return ans;
    }
};