class Solution {
public: 
     
     void  dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>&vis,int r,int c,bool&ans){

       if(r<0 || c<0 || r>=grid2.size() || c>=grid2[0].size()|| vis[r][c]==1|| grid2[r][c]==0) return ;
       if(grid2[r][c]==1 && grid1[r][c]==0){
         ans=true; 
       }
       vis[r][c]=1;
       dfs(grid1,grid2,vis,r+1,c,ans);
      dfs(grid1,grid2,vis,r-1,c,ans);
       dfs(grid1,grid2,vis,r,c+1,ans);
       dfs(grid1,grid2,vis,r,c-1,ans);
       
       





     }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         int m=grid2.size(); int n=grid2[0].size();
      vector<vector<int>>vis(m,vector<int>(n,0)); int ans=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==0 && grid2[i][j]==1){
                bool ak=false;
               dfs(grid1,grid2,vis,i,j,ak);
               if(ak==false) ans++;
            }
        }
      }

       return ans;


    }
};