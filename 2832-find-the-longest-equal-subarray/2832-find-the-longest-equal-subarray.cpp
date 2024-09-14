class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
          unordered_map<int,int>m;
          int i=0,j=0,ans=0;int mx=0;
          while(j<nums.size()){
              m[nums[j]]++;
              mx=max(mx,m[nums[j]]);
              while(j-i+1-mx>k){
                m[nums[i]]--;
                i++;
              }
               ans=max(ans,mx); 
              j++;
          }
          return ans;
    }
};