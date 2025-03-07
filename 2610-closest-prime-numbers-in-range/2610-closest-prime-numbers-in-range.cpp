class Solution {
public:
    void sieveoferatosthenes(int n, vector<bool>& primes){
        primes[0]=primes[1]=false;
        for(int i=2; i<=n; i++){
            if(primes[i] && (long long)i * i <= n){
                for(int j=i*i; j<=n; j+=i){
                    primes[j]=false;
                }
            }   
        }
    }
    vector<int> closestPrimes(int left, int right) {
        int first=-1, second=-1;
        vector<bool> primes(right+1, true);
        sieveoferatosthenes(right, primes);
        int prev=-1;
        int mini=INT_MAX;
        for(int i=left; i<=right; i++){
            if(primes[i]){
                if(prev!=-1 && i-prev<=2){
                    mini=i-prev;
                    first=prev;
                    second=i;
                    break;
                }
                if(prev!=-1 && i-prev<mini){
                    mini=i-prev;
                    first=prev;
                    second=i;
                }
                prev=i;
            }
        }
        return {first, second};
    }
};