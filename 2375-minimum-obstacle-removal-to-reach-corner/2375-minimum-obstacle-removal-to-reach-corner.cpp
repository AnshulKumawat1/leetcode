class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        set<tuple<int,int,int>>s;//no of stones,r,c
        s.emplace(0,0,0);
        int m=grid.size(); int n=grid[0].size();
        vector<vector<int>>dis(m,vector<int>(n,1e9));
        dis[0][0]=0;
        int x[4]={0,0,-1,1};
        int y[4]={1,-1,0,0};
        while(s.size()>0){
         auto[steps,r,c]=*(s.begin());
          s.erase(s.begin());
         
          for(int i=0;i<4;i++){
            int nr=r+x[i]; int nc=c+y[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size()){
                int a=0;
                if(grid[nr][nc]==1) a=1;
                if(dis[nr][nc]>a+steps){
                    dis[nr][nc]=a+steps;
                    s.emplace(a+steps,nr,nc);
                }
            }
          }
        }
       return dis[m-1][n-1];

    }
};