class Solution {
public:
  vector<int>topo(vector<int>adj[],int n){
    vector<int>in(n+1,0);
    for(int i=1;i<n+1;i++){
        for(auto it:adj[i]) in[it]++;
    }
    queue<int>q; vector<int>ans;
    for(int i=1;i<in.size();i++) if(in[i]==0) q.push(i);
    while(q.size()>0){
        int node=q.front(); q.pop();
         ans.push_back(node);
         for(auto child:adj[node]){
            in[child]--;
            if(in[child]==0) q.push(child);
         }
    }
    return ans;

  }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
           vector<int>adj[k+1]; vector<int>adjc[k+1];
           for(auto it:row){
            adj[it[0]].push_back(it[1]);
           }
           for(auto it:col){
            adjc[it[0]].push_back(it[1]);
           }
           vector<int>r=topo(adj,k);
           if(r.size()<k) return {};
           vector<int>c=topo(adjc,k);
           if(c.size()<k ) return {};
            vector<vector<int>>ans(k,vector<int>(k,0));
            unordered_map<int,int>m;
            for(int i=0;i<c.size();i++){
                m[c[i]]=i;
            }
           for(int i=0;i<k;i++){
              ans[i][m[r[i]]]=r[i];
           }
            return ans;
    }
};