class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
         vector<int>r;
         for(int i=0;i<nums.size();i++){
             int sum=0;
            for(int j=i;j<nums.size();j++){
               sum+=nums[j];
               r.push_back(sum);
            }
         }
         sort(r.begin(),r.end());
         left=left-1;
         right=right-1; int ans=0;
         for(int i=left;i<=right;i++){
             ans= ((ans%mod)+(r[i]%mod))%mod;
         }
         return ans;

    }
};