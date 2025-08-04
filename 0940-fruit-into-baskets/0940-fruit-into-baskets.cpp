class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int, int> count; 
        int i=0;
        int j=0;
        int maxlen=0;

        while(j<n){
            count[fruits[j]]++;
            while(count.size()>2){
                count[fruits[i]]--;
                if(count[fruits[i]]==0){
                    count.erase(fruits[i]);
                }
                i++; 
            }
            maxlen=max(maxlen, j-i+1);
            j++;
        }

        return maxlen;
    }
};
