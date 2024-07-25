class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<long long ,long long >m;
        long long  maxi=0;int ans=-1;
        for(int i=0;i<edges.size();i++){
            m[edges[i]]+=i;
            if(maxi<m[edges[i]]){
                maxi=m[edges[i]];
                ans=edges[i];
            }
            if(maxi==m[edges[i]] && ans>edges[i]){
                ans=edges[i];
            }
        }
        return ans;

    }
};