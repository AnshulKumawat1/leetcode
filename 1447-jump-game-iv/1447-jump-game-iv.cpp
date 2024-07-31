class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        for(auto &it:m){
            sort(it.second.begin(),it.second.end());
        }
        queue<tuple<int,int>>q; int n=arr.size();
        q.emplace(0,0); vector<int>vis(n,0); vis[0]=1;
        while(q.size()>0){
          auto[i,steps]=q.front(); q.pop();
          
          if(i==n-1) return steps;
          if(i+1<n && vis[i+1]==0){vis[i+1]=1; q.emplace(i+1,steps+1); }
          if(i-1>=0 && vis[i-1]==0){vis[i-1]=1; q.emplace(i-1,steps+1);}
          for(int j=m[arr[i]].size()-1;j>=0;j--){
            if(vis[m[arr[i]][j]]==0){
                vis[m[arr[i]][j]]=1; q.emplace(m[arr[i]][j],steps+1);
            }
          }
          m.erase(arr[i]);

        }

return -1;

    }
};