#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
     
        vector<pair<int, int>> adj[n];
        
        
        queue<tuple<int, int, int>> q;
        q.emplace(0, -1, 0);
        
        
        for(auto it : r) adj[it[0]].push_back({it[1], 0});
        for(auto it : b) adj[it[0]].push_back({it[1], 1});
        
        
        vector<int> ans(n, 1e9);
         ans[0] = 0; 
        
         set<tuple<int,int>>s; s.insert({0,-1});
        while(!q.empty()) {
            auto [node, prev, steps] = q.front(); q.pop();
            cout<<node<<" ";
            //    ans[node]=steps;
            
            for(auto child : adj[node]) {
                int adjnode = child.first;
                int col = child.second;
                
               
                if(prev == -1 || prev != col) {
                    if(ans[adjnode] > steps+1) {
                        ans[adjnode] =steps+1;
                        
                  
                    }
                 
                if(s.find({adjnode,col})==s.end()){
                    s.emplace(adjnode,col);
                    q.emplace(adjnode,col,steps+1);
                }

                  
                }
            }
        }
        
       
        for(auto &it : ans) {
            if(it == 1e9) it = -1;
        }
        
        return ans;
    }
};
