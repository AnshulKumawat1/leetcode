class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
         set<tuple<int,int,int>>s;
         int m=h.size(); int n=h[0].size();
         s.emplace(0,0,0);
         int x[4]={-1,1,0,0};
         int y[4]={0,0,-1,1};
         vector<vector<int>>dis(m,vector<int>(n,1e9));
         dis[0][0]=0;
         while(s.size()>0){
            auto[diff,r,c]=*(s.begin()); s.erase(s.begin());
            for(int i=0;i<4;i++){
             int nr=r+x[i]; int nc=c+y[i];
             if(nr>=0 && nc>=0 && nr<m && nc<n  ){
                int maxi=max(diff,abs(h[nr][nc]-h[r][c]));
                if(maxi<dis[nr][nc]){
                    dis[nr][nc]=maxi; s.emplace(maxi,nr,nc);
                }
             }
            }
         }
         return dis[m-1][n-1];

    }
};