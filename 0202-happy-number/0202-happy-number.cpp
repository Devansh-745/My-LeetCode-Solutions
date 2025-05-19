class Solution {
public:
    int getsum(int n){
        int sum=0;
        while(n!=0){
            int dig=n%10;
            sum+=dig*dig;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n==1 || n==7) return true;
        unordered_set<int> store;
        int sum=getsum(n);
        store.insert(sum);
        while(sum!=1){
            sum=getsum(sum);
            if(store.find(sum)!=store.end()){
                return false;
            }
            store.insert(sum);
        }
        return true;
    }
};