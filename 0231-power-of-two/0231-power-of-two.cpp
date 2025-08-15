class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int x=round(log(n)/log(2));
        if(pow(2, x)==n) return true;
        return false;
    }
};