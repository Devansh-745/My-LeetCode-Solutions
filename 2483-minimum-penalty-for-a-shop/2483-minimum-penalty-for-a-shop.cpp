class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        int minhour=0;
        int penalty=0;
        for(int i=0; i<n; i++){
            if(customers[i]=='Y'){
                penalty++;
            }
        }
        
        int minpenalty=penalty;

        for(int i=0; i<n; i++){
            if(customers[i]=='Y') penalty--;
            else penalty++;
            
            if(penalty<minpenalty){
                minhour=i+1;
                minpenalty=penalty;
            }
        }
        
        return minhour;
    }
};