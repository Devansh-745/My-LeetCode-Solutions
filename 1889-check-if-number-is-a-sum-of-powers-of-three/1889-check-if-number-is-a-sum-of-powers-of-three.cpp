class Solution {
public:
    bool checker(vector<int>& powers, int n, int i, int &cursum){
        if(cursum==n){
            return true;
        }
        if(i>=powers.size()){
            return false;
        }
        cursum+=powers[i];
        if(checker(powers, n, i+1, cursum)) return true;
        cursum-=powers[i];
        if(checker(powers, n, i+1, cursum)) return true;
        return false;
    }
    bool checkPowersOfThree(int n) {
        vector<int> powers;
        int i=0;
        while(pow(3, i)<=n){
            powers.push_back(pow(3, i));
            i++;
        }
        int cursum=0;
        return checker(powers, n, 0, cursum);
    }
};