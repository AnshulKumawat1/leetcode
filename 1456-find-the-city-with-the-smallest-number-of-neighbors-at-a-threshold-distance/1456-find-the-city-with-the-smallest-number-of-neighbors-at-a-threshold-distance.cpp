class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
            vector<pair<int,int>>adj[n];
            for(auto it:edges){
                int u=it[0]; int v=it[1]; int w=it[2];
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
            vector<vector<int>>dis(n,vector<int>(n,1e9));
            for(int i=0;i<n;i++){
                dis[i][i]=0;
            }
            for(int i=0;i<n;i++){
                for(auto child:adj[i]){
                    dis[i][child.first]=child.second;
                }
            }
            for(int via=0;via<n;via++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        dis[i][j]=min(dis[i][j],dis[i][via]+dis[via][j]);
                    }
                }
            }
               int mini=1e9; int ans=-1;
            for(int i=0;i<n;i++){
                 int citypas=0;
                for(int j=0;j<n;j++){
                   if(dis[i][j]<=th) citypas++;
                } 
                if(mini>=citypas) {ans=i; mini=citypas;}
            }
            return ans;
    }
};