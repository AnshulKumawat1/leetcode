class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arr, vector<int>& l) {
        vector<int>ans(k,0);
        set<int>a;
        for(int i=0;i<k;i++) a.insert(i); // available
        set<pair<int,int>>o;
        for(int i=0;i<arr.size();i++){
            int start=arr[i]; int end=l[i];
          while(o.size()>0 && (*o.begin()).first<=start){
               int ser=(*o.begin()).second;
               o.erase(o.begin());
               a.insert(ser);
           }
          if(a.size()==0){
            continue;
          }
          else{
            int ser=i%k;
            auto it=a.lower_bound(ser);
            if(it==a.end()) it=a.begin();
             ser=*it;
             ans[ser]++;
             a.erase(it);
             o.insert({end+start,ser});

          }
        }
        int maxi=*max_element(ans.begin(),ans.end());
        vector<int>ak;
        for(int i=0;i<ans.size();i++){
            if(maxi==ans[i]) ak.push_back(i);
        }
        return ak;


    }
};