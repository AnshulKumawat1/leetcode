class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& qu) {
        vector<int>adj[qu.size()];
        vector<int>in(qu.size(),0);
        for(auto it:r){
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        queue<int>q; int n=qu.size(); vector<int>ans(n);
        for(int i=0;i<qu.size();i++) ans[i]=i;
        
        for(int i=0;i<n;i++){
            if(in[i]==0){
               q.push(i);
            }
        }
        while(q.size()>0){
            int parent=q.front();q.pop();
            for(auto child:adj[parent]){
                if(qu[ans[child]]>qu[ans[parent]]) ans[child]=ans[parent];
                in[child]--;
                if(in[child]==0) q.push(child);
            }
        }
    return ans;
    }
};