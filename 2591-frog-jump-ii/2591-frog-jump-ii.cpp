class Solution {
public:
    bool possible(int mid, vector<int>& stones, int n){
        int cost=INT_MAX;
        vector<bool> visit(n, false);
        int i=0;
        while(i<n-1){
            int j=i;
            while(j+1<n && stones[j+1]-stones[i]<=mid) j++;
            if(j==i) return false; 
            visit[j]=true;
            i=j;
        }
        vector<int> notvisited;
        for(int j=0; j<n-1; j++){
            if(!visit[j]) notvisited.push_back(j);
        }
        notvisited.push_back(n-1);
        i=notvisited.size() - 1;
        while(i>0){
            int j=i;
            while(j>0 && stones[notvisited[j]]-stones[notvisited[j-1]]<=mid) j--;
            if(j==i) return false;
            i=j;
        }
        return true;
    }
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int low=0;
        int high=stones[n-1]-stones[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid, stones, n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};