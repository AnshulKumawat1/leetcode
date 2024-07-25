class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& w, vector<vector<int>>& friends, int id, int level) {
        vector<int>adj[w.size()];
        set<string>akl;
        for(int i=0;i<friends.size();i++){
            for(auto it:friends[i]){
                adj[i].push_back(it);
            }
        }
         vector<int>vis(w.size(),0);
         queue<int>q;  vis[id]=1;
         int l=1;
         q.push(id); vector<string>ans;
         while(q.size()>0){
            int size=q.size();
            vector<int>ak;
            while(size--){
               int node=q.front(); q.pop();
               ak.push_back(node);
               for(auto it:adj[node]){
                if(vis[it]==0){
                    vis[it]=1; q.push(it);
                }
               }
            }
            if(l==level+1){
               unordered_map<string ,int>m;
               for(int i=0;i<ak.size();i++){
                    int n=ak[i]; cout<<n<<" ";
                  for(auto iti:w[n]){
                     m[iti]++;
                  }
               }
                 vector<pair<int,string>>v;
                 for(auto it:m){
                    v.push_back({it.second,it.first});
                 }
                 sort(v.begin(),v.end());
                 for(auto it:v){
                    ans.push_back(it.second);
                 }
                 return ans;
              
              break;
            }
            l++;
         }
         
         return ans;

    }
};