class Solution {
public:
      vector<int>solve(vector<int>adj[],int src ,int n){
          vector<int>dis(n,1e9);
          dis[0]=0;
          set<tuple<int,int>>s;
          s.emplace(0,0);
          while(s.size()>0){
              auto[steps,node]=*(s.begin()); s.erase(s.begin());
              
              for(auto it:adj[node]){
                  if(steps+1<dis[it]){
                      if(dis[it]!=1e9) s.erase({dis[it],it});
                      dis[it]=steps+1; s.emplace(dis[it],it);
                  }
              }
          }
          
          return dis;
              
      }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
          vector<int>adj[n]; vector<int>ans;
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        for(auto it:queries){
            adj[it[0]].push_back(it[1]);
             vector<int>dis=solve(adj,0,n);
            ans.push_back(dis[n-1]);

        }
        return ans;
    }
};