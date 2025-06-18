class Solution {
public:
    // bool achievable(vector<int>& nums, int x, int mid, int n){
    //     for(int i=0; i<n; i++){
    //         int cur=nums[i];
    //         for(int j=i+x; j<n; j++){
    //             if(abs(cur-nums[j])<=mid){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    // bool achievable(vector<int>& nums, int x, int mid, int n){
    //     set<int> st;
    //     //Forward Direction: j>=i+x
    //     for(int i=x; i<n; i++){
    //         st.insert(nums[i]);
    //     }

    //     for(int i=0; i<n-x; i++){
    //         //try to find a close value for nums[i]
    //         auto it=st.lower_bound(nums[i]); // (>=)

    //         if(it!=st.end() && abs(*it-nums[i])<=mid) return true; //smallest number >= nums[i]
    //         if(it!=st.begin()){ 
    //             it--;
    //             if(abs(*it-nums[i])<=mid) return true; //the largest number < nums[i]
    //         }

    //         //erase nums[i+x] for next iteration, as it will no longer satisfy the condition
    //         st.erase(nums[i+x]);
    //     }

    //     st.clear();

    //     //Backward direction: j<=i-x
    //     for(int i=0; i<=n-x-1; i++){
    //         st.insert(nums[i]);
    //     }

    //     for(int i=x; i<n; i++){
    //         auto it=st.lower_bound(nums[i]);

    //         if(it!=st.end() && abs(*it-nums[i])<=mid) return true;
    //         if(it!=st.begin()){
    //             it--;
    //             if(abs(*it-nums[i])<=mid) return true;
    //         }
    //         st.erase(nums[i-x]);
    //     }
    //     return false;
    // }
    // bool achievable(vector<int>& nums, int x, int mid, int n) {
    //     set<pair<int, int>> st;

    //     for (int i = x; i < n; i++) {
    //         st.insert({nums[i], i});
    //     }

    //     for (int i = 0; i < n - x; i++) {
    //         auto it = st.lower_bound({nums[i], -1});  // lower_bound by value

    //         if (it != st.end() && abs(it->first - nums[i]) <= mid && abs(it->second - i) >= x)
    //             return true;

    //         if (it != st.begin()) {
    //             --it;
    //             if (abs(it->first - nums[i]) <= mid && abs(it->second - i) >= x)
    //                 return true;
    //         }

    //         st.erase({nums[i + x], i + x});
    //     }

    //     // Backward direction
    //     st.clear();
    //     for (int i = 0; i <= n - x - 1; i++) {
    //         st.insert({nums[i], i});
    //     }

    //     for (int i = x; i < n; i++) {
    //         auto it = st.lower_bound({nums[i], -1});

    //         if (it != st.end() && abs(it->first - nums[i]) <= mid && abs(it->second - i) >= x)
    //             return true;

    //         if (it != st.begin()) {
    //             --it;
    //             if (abs(it->first - nums[i]) <= mid && abs(it->second - i) >= x)
    //                 return true;
    //         }

    //         st.erase({nums[i - x], i - x});
    //     }

    //     return false;
    // }

    bool achievable(vector<int>&nums, int x, int mid, int n) {
		set<int> s; 
		for(int i=n-x-1; i>=0; i--){
			s.insert(nums[i+x]);
			
			auto it=s.lower_bound(nums[i]);
			if(it==s.begin()){
				if(abs(*it-nums[i])<=mid) return true;
			} 
            else{
				if(it!=s.end() && abs(*it-nums[i]) <=mid) return true;
				it--;
				if (abs(*it-nums[i]) <= mid) return true;
			}
		}
		return false;
	}

    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        int low=0;
        int high=*max_element(nums.begin(), nums.end())-*min_element(nums.begin(), nums.end());
        int ans=INT_MAX;
        vector<int> precomp(n);
        for(int i=0; i<n; i++){
            
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(achievable(nums, x, mid, n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};