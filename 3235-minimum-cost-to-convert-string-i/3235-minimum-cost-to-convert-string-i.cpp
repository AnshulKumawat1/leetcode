class Solution {
public:
     vector<int>dijkstra(int n,vector<pair<int,int>>adj[],int src){
        set<pair<int,int>>s;
        s.insert({0,src});
        vector<int>dis(n,1e9); dis[src]=0;
        while(s.size()>0){
            auto it=*s.begin();
            int node=it.second;
            int dist=it.first;
            s.erase(s.begin());
            for(auto child:adj[node]){
                int adjnode=child.first;
                int weig=child.second;
                if(weig+dist<dis[adjnode]){
                    dis[adjnode]=weig+dist;
                    s.insert({dis[adjnode],adjnode});
                }
            }
        }
        return dis;
     }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans=0;
         vector<pair<int,int>>adj[26];
         for(int i=0;i<original.size();i++){
            int from=original[i]-'a';int  to=changed[i]-'a'; int cos=cost[i];
             adj[from].push_back({to,cos});
         }
          map<pair<int,int>,int>m;
         for(int i=0;i<source.size();i++){
             int from=source[i]-'a';int  to=target[i]-'a';
             if(m.find({from,to})!=m.end()){ ans+=m[{from,to}]; continue;}
             vector<int>dis= dijkstra(26,adj,from);
             if(dis[to]>=1e9) return -1;
              ans+=dis[to];
              m[{from,to}]=dis[to];

         }
         return ans;
    }
};