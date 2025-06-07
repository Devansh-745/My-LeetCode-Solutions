class Solution {
public:
    int calc(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        return calc(n-1) + calc(n-2);
    }
    int fib(int n){
        return calc(n);
    }
};
