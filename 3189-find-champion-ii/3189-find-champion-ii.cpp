class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
         vector<int>adj[n]; vector<int>in(n,0);
         for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
         }
         queue<int>q;
         for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
         }
         if(q.size()>1) return -1;
         else return q.front();
        
        
    }
};