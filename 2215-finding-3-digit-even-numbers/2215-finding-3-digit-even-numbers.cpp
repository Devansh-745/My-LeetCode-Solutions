class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> mp;
        for(int i=0; i<digits.size(); i++){
            mp[digits[i]]++;
        }
        vector<int> ans;
        for(int i=100; i<1000; i+=2){ //Only even numbers
            string num=to_string(i);
            unordered_map<int, int> temp = mp;
            bool valid=true;
            for(char c : num){
                int d = c-'0';
                if(temp[d] <= 0){
                    valid=false;
                    break;
                }
                temp[d]--;
            } 
            if(valid){
                ans.push_back(i);
            }
        }
        return ans;
    }
};