class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> freq;
        int tot=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                freq[nums[i]*nums[j]]++;
            }
        }
        for(auto it : freq){
            int f=it.second;
            int prod=it.first;
            int curtot= f*(f-1)/2;
            tot+=8*curtot;
        }
        return tot;
    }
};