class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0;
        int j=n-1;
        int first=0;
        int second=0;
        while(i<j){
            if(numbers[i]+numbers[j]>target){
                j--;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            if(numbers[i]+numbers[j]==target){
                first=i+1;
                second=j+1;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};