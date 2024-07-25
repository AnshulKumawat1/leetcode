class Solution {
public:
    vector<int>top(vector<int>adj[],int n){
          vector<int>in(n,0);
          for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                in[it]++;
            }
          }
          queue<int>q; vector<int>ans;
          for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
          }
          while(q.size()>0){
           int node=q.front();q.pop();
           ans.push_back(node);
           for(auto it:adj[node]){
            in[it]--;
            if(in[it]==0)q.push(it);
           }
          }
          return ans;
    }
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& supplies) {
        set<string>s;
        map<string,int>m;
        for(int i=0;i<r.size();i++){
            s.insert(r[i]);
            m[r[i]]=i;
        }
        vector<int>adj[r.size()];
        for(int i=0;i<ing.size();i++){
           for(auto it:ing[i]){
            if(s.find(it)!=s.end()){
                adj[m[it]].push_back(i);
            }
           }
        }

     vector<string>ans;
        vector<int>topo=top(adj,r.size());
        // set<string >ak;
        unordered_set<string>sup;
        for(auto it:supplies){
             sup.insert(it);
        }
        
        for(auto it:topo){
            bool flag=true;
          for(int i=0;i<ing[it].size();i++){
            if(sup.find(ing[it][i])==sup.end()){
                flag=false; break;
            }
          }
          if(flag==true){
            ans.push_back(r[it]);
            sup.insert(r[it]);
          }
        }
      
        return ans;

    }
};