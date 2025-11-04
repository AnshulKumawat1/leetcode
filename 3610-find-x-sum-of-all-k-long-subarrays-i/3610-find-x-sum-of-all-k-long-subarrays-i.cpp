class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
         
         vector<int>ans;
         int i=0,j=0;
         set<pair<int,int>,greater<pair<int,int>>>s;
         map<int,int>m;
         while(j<nums.size()){
          if(m.find(nums[j])==m.end()){
             m[nums[j]]++;
             s.insert({m[nums[j]],nums[j]});
          }
          else{
              int fre=m[nums[j]];
              m[nums[j]]++;
              s.erase(s.find({fre,nums[j]}));
              s.insert({m[nums[j]],nums[j]});
          }
         if(j-i+1==k){
            int ak=0; int k=0;
            for(auto it:s){
               ak+=it.first*it.second;
               k++;
               if(k==x) break;
            }
            ans.push_back(ak);
            int fre=m[nums[i]];
             m[nums[i]]--;
            if(m[nums[i]]==0){
               s.erase(s.find({fre,nums[i]}));
               m.erase(nums[i]);
            }
            else {
                s.erase(s.find({fre,nums[i]}));
                fre--;
                s.insert({fre,nums[i]});
            }
            i++;
         }
           
           j++;

         }
         return ans;
    }
};