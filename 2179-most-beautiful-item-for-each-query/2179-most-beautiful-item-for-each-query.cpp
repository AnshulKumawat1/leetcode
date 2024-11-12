class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
           sort(items.begin(),items.end());
           vector<pair<int,int>>rq(q.size());
           for(int i=0;i<q.size();i++){
              rq[i].first=q[i];
              rq[i].second=i;
           }
           vector<int>ans;
           set<int>s; sort(rq.begin(),rq.end()); int i=0;
           for(auto it:rq){
            int val=it.first; 
            while(i<items.size() && items[i][0]<=val){
                  s.insert(items[i][1]); i++;
            }
            if(s.size()==0) ans.push_back(0);
            else {
                auto ak=s.end(); ak--; ans.push_back(*ak);
            }
           } vector<int>real(rq.size());
            for(int i=0;i<rq.size();i++){
              real[rq[i].second]=ans[i];
            }
            return real;

    }
};