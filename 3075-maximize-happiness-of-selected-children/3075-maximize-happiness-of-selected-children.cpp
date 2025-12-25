class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.rbegin(), happiness.rend());
        long long sum=0;
        for(int i=0; i<k; i++){
            int add=happiness[i]-i;
            if(add<=0) add=0;
            sum+=add;
        }
        return sum;
    }
};