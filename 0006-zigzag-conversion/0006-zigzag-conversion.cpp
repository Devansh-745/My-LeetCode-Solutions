class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> zigzag(numRows, vector<char>(2*s.length(), '|'));
        bool flag=true;
        int i=0, j=0;
        for(auto c : s){
            zigzag[i][j]=c;
            if(flag){ //move down
                if(i==numRows-1){
                    flag=false;
                    i=i-1;
                    j=j+1;
                } 
                else{
                    i+=1;
                }
            } 
            else { //move up (diagonally)
                if(i==0){
                    flag=true;
                    i+=1; 
                } 
                else{
                    i-=1; 
                    j+=1;
                }
            }
        }
        int n=zigzag.size();
        int m=zigzag[0].size();
        string ans="";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(zigzag[i][j]!='|') ans+=zigzag[i][j];
            }
        }
        return ans;
    }
};