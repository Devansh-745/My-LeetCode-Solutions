class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        if(k>n) return 0;
        vector<int> copy=colors;
        for(int i=0; i<k-1; i++){
            copy.push_back(colors[i]); //to make the circular array linear
        }
        int left=0;
        int right=1;
        int count=0;
        while(right<copy.size()){
            if(copy[right]==copy[right-1]){ //pattern breaks, reset
                left=right;
                right++;
                continue;
            }
            right++;
            if(right-left<k) continue; //dont count
            count++;
            left++;
        }
        return count;
    }
};