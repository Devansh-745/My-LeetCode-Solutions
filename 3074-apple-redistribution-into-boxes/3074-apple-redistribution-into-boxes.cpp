class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());

        int need=0;
        while(sum > 0){
            sum-=capacity[need];
            need+=1;
        }

        return need;
    }
};