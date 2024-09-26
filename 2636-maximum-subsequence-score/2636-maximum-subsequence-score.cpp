class Solution {
public:
     
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
          vector<pair<int,int>>v;
          for(int i=0;i<nums1.size();i++){
              v.push_back({nums2[i],nums1[i]});
          }
          sort(v.begin(),v.end(),greater<pair<int,int>>());
          for(auto it:v){
             cout<< it.first<<" ";
          }
          cout<<endl;
          for(auto it:v){
             cout<<it.second<<" ";
          }
          long long ans=0,sum=0; multiset<int>s;
         for(int i=0;i<v.size();i++){
             int miel=v[i].first;
             if(s.size()<k-1) {
                  s.insert(v[i].second); sum+=v[i].second; continue;
             }
               s.insert(v[i].second); sum+=v[i].second;
             ans=max(ans,sum*1LL*miel);
             sum-=*s.begin(); s.erase(s.begin());
             

         }
          return ans;

    }
};