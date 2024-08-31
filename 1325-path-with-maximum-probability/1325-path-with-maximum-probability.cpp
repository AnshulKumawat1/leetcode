class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        vector<pair<int,double>>adj[n];
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0]; int v=edges[i][1];
          adj[u].push_back({v,succ[i]});
          adj[v].push_back({u,succ[i]});
       }
      set<tuple<double,int>>s;
       vector<double>dis(n,0);
        dis[start]=1;
        s.emplace(1,start);
        while(s.size()>0){
            auto[steps,node]=(*s.rbegin()); 
            auto it=s.end(); it--;
            s.erase(it);
          
            for(auto it:adj[node]){
                int adjnode=it.first;
                double w=it.second;
                if(w*steps>dis[adjnode]){
                    if(dis[adjnode]!=1e9) s.erase({dis[adjnode],adjnode});
                    s.emplace(w*steps,adjnode);
                    dis[adjnode]=w*steps;

                }
            }
        }
        if(dis[end]==0) return 0;
        return dis[end];
    }
};