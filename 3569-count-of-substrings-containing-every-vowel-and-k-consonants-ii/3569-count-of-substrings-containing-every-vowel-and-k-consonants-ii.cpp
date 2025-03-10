class Solution {
public:
    bool voworcons(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ) return true;
        return false;
    }
    long long countOfSubstrings(string word, int k) {
        long long n=word.length();
        long long left=0;
        long long right=0;
        long long count=0;
        vector<long long> nextcons(n);
        long long lastconi=n;
        for(long long i=n-1; i>=0; i--){
            nextcons[i]=lastconi;
            if(!voworcons(word[i])){
                lastconi=i;
            }
        }
        unordered_map<char, long long> vowcount;
        long long conscount=0;
        while(right<n){
            if(voworcons(word[right])){
                vowcount[word[right]]++;
            }
            else{
                conscount++;
            }
            while(left<n && conscount>k){
                if(!voworcons(word[left])){
                    conscount--;
                }
                else{
                    vowcount[word[left]]--;
                    if(vowcount[word[left]]==0){
                        vowcount.erase(word[left]);
                    }
                }
                left++;
            }
            while(left<n && conscount==k && vowcount.size()==5){
                count+=(nextcons[right]-right);
                if(!voworcons(word[left])){
                    conscount--;
                }
                else{
                    vowcount[word[left]]--;
                    if(vowcount[word[left]]==0){
                        vowcount.erase(word[left]);
                    }
                }
                left++;
            } 
            right++;    
        }
        return count;
    }
};