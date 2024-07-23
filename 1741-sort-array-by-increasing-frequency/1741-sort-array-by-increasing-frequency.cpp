class Solution {
public:
      static bool mycmpa(pair<int,int>&a,pair<int,int>&b){
           if(a.second==b.second) return a.first>b.first;
           return a.second<b.second;

       }
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<int >ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
         vector<pair<int,int>> v;
         for(int i=0;i<nums.size();i++){
               v.push_back({nums[i],m[nums[i]]});
         }


          sort(v.begin(),v.end(),mycmpa);
            for(auto &i:v){
                  ans.push_back(i.first);
            }

          return ans;

    }
};