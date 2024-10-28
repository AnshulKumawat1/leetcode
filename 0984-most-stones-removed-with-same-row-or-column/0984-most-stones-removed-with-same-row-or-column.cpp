class Solution {
public:
       void dfs(vector<vector<int>>& stones,vector<int>&vis,int ind ){
            vis[ind]=1;
            for(int i=0;i<stones.size();i++){
             if(vis[i]==0 && stones[i][0]==stones[ind][0] ){
                dfs(stones,vis,i);
             }
             if(vis[i]==0 && stones[i][1]==stones[ind][1]){
                 dfs(stones,vis,i);
             }
            }
       }
    int removeStones(vector<vector<int>>& stones) {
           int n=stones.size();
          
           vector<int>vis(stones.size(),0);
           int cnt=0;
           for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++; dfs(stones,vis,i);
            }
           }
          return stones.size()-cnt;
         
    }
};