class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
         vector<int>adj[n];
        for(int i=0;i<graph.size();i++){
           for(auto it:graph[i]){
            adj[i].push_back(it);
           }
        }
        int final=(1<<n)-1;
        int ini=0;
        queue<tuple<int,int,int>>q; set<pair<int,int>>s;
        for(int i=0;i<n;i++){
            int mask=1<<i;
            q.emplace(i,mask,0);
            s.insert({i,mask});
        }
       
       while(q.size()>0){
        auto[node,mask,steps]=q.front();q.pop();
        if(mask==final) return steps;
        for(auto child:adj[node]){
            int nm=mask|(1<<child);
            if(s.find({child,nm})==s.end()){
                s.insert({child,nm}); q.emplace(child,nm,steps+1);
            }
        }
       }
       return -1;





    }
};