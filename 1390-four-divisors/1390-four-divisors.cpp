class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            int num=nums[i];
            int cursum=0;
            int count=0;
            for(int i=1; i<=sqrt(num); i++){
                if(num%i==0){
                    if(num/i==i){
                        cursum+=i;
                        count++;
                    }
                    else{
                        cursum+=i;
                        cursum+=num/i;
                        count+=2;
                    }
                }
            }
            if(count==4){
                sum+=cursum;
            }
        }
        return sum;
    }
};