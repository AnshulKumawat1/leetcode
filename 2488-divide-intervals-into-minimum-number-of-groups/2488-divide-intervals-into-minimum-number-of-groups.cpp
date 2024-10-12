class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int>m;
        for(auto it:intervals){
            m[it[0]]++;
            m[it[1]+1]--;
        }
        int ans=0;  int t=0;
         
        for(auto it:m){
          t+=it.second;
          m[it.first]=t;
          ans=max(ans,m[it.first]);
        }
        return ans;
    }
};