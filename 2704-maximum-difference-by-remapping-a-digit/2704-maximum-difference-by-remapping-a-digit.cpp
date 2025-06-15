class Solution {
public:
    int minMaxDifference(int num) {
        string maxi=to_string(num);
        string mini=maxi;
        int m=maxi.size();
        for(int i=0; i<m; i++){
            if(maxi[i]=='9'){
                continue;
            }
            else{
                char first=maxi[i];
                maxi[i]='9';
                for(int j=i; j<m; j++){
                    if(maxi[j]==first){
                        maxi[j]='9';
                    }
                }
                break;
            }
        }
        
            for(int i=0; i<m; i++){
                if(mini[i]=='0'){
                    continue;
                }
                else{
                    char first=mini[i];
                    mini[i]='0';
                    for(int j=i; j<m; j++){
                        if(mini[j]==first){
                            mini[j]='0';
                        }
                    }
                    break;
                }
            }
        
        
            // char first=mini[0];
            // mini[0]='1';
            // for(int i=0; i<m; i++){
            //     if(mini[i]==first){
            //         mini[i]='1';
            //     }
            // }
        
        int maxnum=stoi(maxi);
        int minnum=stoi(mini);
        return maxnum-minnum;
    }
};