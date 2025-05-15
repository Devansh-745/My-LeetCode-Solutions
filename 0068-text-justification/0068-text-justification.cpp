class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        int n=words.size();
        vector<string> res;
        int i=0;
        
        while(i<n){
            string cur;
            int sum=0;
            int nums=0;
            int start=i;

            while(i<n && sum+words[i].length()+nums<=maxWidth){
                sum+=words[i].length();
                nums++;
                i++;
            }
            
            int diff=maxWidth-sum;
            
            //for last line or single word line
            if(i==n || nums==1){
                for(int j=start; j<i; j++){
                    cur+=words[j];
                    if(j < i-1) cur+=" ";
                }
                while(cur.length() < maxWidth) cur+=" ";
            }
            else{
                int spaces=diff / (nums-1);
                int extra=diff % (nums-1); 
                //imp
                for(int j=start; j<i; j++){
                    cur+=words[j];
                    if(j<i-1){
                        cur+=string(spaces, ' ');
                        if(extra>0){
                            cur+=" ";
                            extra--;
                        }
                    }
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};