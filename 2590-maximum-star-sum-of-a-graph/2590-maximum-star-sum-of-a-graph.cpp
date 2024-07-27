class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
         vector<int>adj[n];
         for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
         }
         int ans=-1e9;
         for(int i=0;i<n;i++){
            multiset<int,greater<int>>s;
            for(auto child:adj[i]){
               s.insert(vals[child]);
            }
            int a=k; int sum=vals[i]; 
            while(a>0 && s.size()>0){

                int l=*(s.begin()); 
                 if(l<0) break;
                 sum+=l; s.erase(s.begin());
                 a--;
            }
          
            ans=max(ans,sum);
         }
        
         return ans;
    }
};