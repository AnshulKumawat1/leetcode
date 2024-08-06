class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
         set<int>s;
         for(int i=0;i<n;i++)s.insert(i);
         vector<int>ans;
         for(auto it:queries){
            auto l=s.lower_bound(it[0]+1);
            auto r=s.upper_bound(it[1]-1);
            s.erase(l,r);
            ans.push_back(s.size()-1);

         }
         return ans;
    }
};