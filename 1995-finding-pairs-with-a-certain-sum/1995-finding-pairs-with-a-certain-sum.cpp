class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(auto it : nums2){
            freq[it]++;
        }
    }
    
    void add(int index, int val) {
        freq[nums2[index]]--;
        nums2[index]+=val;
        freq[nums2[index]]++;
    }
    // TWO SUM APPROACH
    int count(int tot) {
        int n1=nums1.size();
        int n2=nums2.size();
        int c=0;
        for(int i=0; i<n1; i++){
            int rem=tot-nums1[i];
            if(freq.find(rem)!=freq.end()) c+=freq[rem];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */