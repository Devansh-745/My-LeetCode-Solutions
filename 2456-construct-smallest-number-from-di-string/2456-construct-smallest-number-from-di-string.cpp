class Solution {
public:
    bool check(string &sequence, string &pattern) {
        for(int i = 0; i < pattern.size(); i++){
            if(pattern[i] == 'I'){
                if(sequence[i] > sequence[i+1]) return false;
            }
            else{
                if(sequence[i] < sequence[i+1]) return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) {
        int n=pattern.size();
        string sequence = "";

        for(int num=1; num<=1+n; num++){
            sequence.push_back(num+'0');
        }

        string perm=sequence;

        while(!check(perm, pattern)){
            next_permutation(perm.begin(), perm.end());
        }
        return perm;
    }
};