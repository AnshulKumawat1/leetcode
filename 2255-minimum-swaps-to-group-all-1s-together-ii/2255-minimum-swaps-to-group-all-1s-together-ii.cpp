class Solution {
public:
    int minSwaps(vector<int>& nums) {
      int ans=1e9;
      int cnt=0;
      int i=0,j=0;
      for(auto it:nums) if(it==1) cnt++;
      vector<int>v;
      if(cnt==0) return 0;
      for(auto it:nums) v.push_back(it);
      for(auto it:nums) v.push_back(it);

      int ak=0;
      while(j<v.size()){
        if(v[j]!=1) ak++;
        if(j-i+1==cnt){
            ans=min(ans,ak);
            if(v[i]!=1) ak--; i++; 
        }
        j++;
      }
      if(ans==1e9) return 0;
      return ans;
    }
};