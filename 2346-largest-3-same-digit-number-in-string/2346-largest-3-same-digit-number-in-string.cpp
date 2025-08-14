class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        int i=0;
        int j=0;
        string ans="";
        unordered_map<char, int> freq;
        while(j<n){
            if(j-i+1>3){
                freq[num[i]]--;
                // if(freq[num[i]]==0){
                //     freq.remove(num[i]);
                // }
                i++;
            }
            freq[num[j]]++;
            if(j-i+1==3){
                if(freq[num[j]]==3){
                    if(ans=="" || ans[0]<num[j]){
                        ans=num.substr(i, 3);
                    }
                    else{
                        continue;
                    }
                }
            }
            j++;
        }
        return ans;
    }
};