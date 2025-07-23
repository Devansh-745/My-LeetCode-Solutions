class Solution {
public:
    // int pointsfinder(string &s, string target, int gain){
    //     int points=0;
    //     stack<char> st;
    //     for(int i=0; i<s.length(); i++){
    //         char cur=s[i];
    //         if(!st.empty() && st.top()==target[0] && cur==target[1]){
    //             st.pop();
    //             points+=gain;
    //         }
    //         else{
    //             st.push(cur);
    //         }
    //     }
    //     //reconstruct remaining string;
    //     string temp="";
    //     while(!st.empty()){
    //         temp+=st.top();
    //         st.pop();
    //     }
    //     reverse(temp.begin(), temp.end());
    //     s=temp;
    //     return points;
    // }
    int pointsfinderII(string &s, string target, int gain){
        int i=0;
        int j=0;
        string temp=s;
        int n=s.length();
        int points=0;
        while(j<n){
            temp[i]=temp[j];
            i++;
            if(i-1>=0 && i-2>=0 && temp[i-1]==target[1] && temp[i-2]==target[0]){
                points+=gain;
                i-=2;
            } 
            j++;
        }
        temp.erase(temp.begin()+i, temp.end());
        s=temp;
        return points;
    }
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        int ans=0;
        string first="ab";
        string second="ba";
        if(x>y){
            ans+=pointsfinderII(s, first, x);
            ans+=pointsfinderII(s, second, y);
        }
        else{
            ans+=pointsfinderII(s, second, y);
            ans+=pointsfinderII(s, first, x);
        }
        return ans;
    }
};