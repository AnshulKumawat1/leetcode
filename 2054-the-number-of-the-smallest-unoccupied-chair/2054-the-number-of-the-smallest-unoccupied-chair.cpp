class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
          for(int i=0;i<times.size();i++){
             times[i].push_back(i);
          }
           sort(times.begin(),times.end());
           set<int>u;
           set<pair<int,int>>o;
           int i=0;
           vector<int>ans(times.size());
           for(int j=0;j<times.size();j++){
             int start=times[j][0]; int end=times[j][1];
                while(o.size()>0 && (*o.begin()).first<=start){
                     int seat=(*o.begin()).second;
                     o.erase(o.begin());
                     u.insert(seat);
                }
            
                if(u.size()>0){
                   int seat=*u.begin();
                    u.erase(seat);
                    o.insert({end,seat}); ans[times[j][2]]=seat;
                }  
                else{
                    o.insert({end,i}); ;ans[times[j][2]]=i; i++;
                }
           }
           return ans[t];
           
    }
};