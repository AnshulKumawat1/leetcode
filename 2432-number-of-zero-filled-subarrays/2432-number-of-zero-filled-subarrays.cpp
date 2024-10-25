class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
         long long ans=0;
         int i=0,j=0;
         while(j<nums.size()){
             if(nums[j]==0){
                     i=j;
                 while(j<nums.size() && nums[j]==0 ){
                     ans+=j-i+1; j++;
                 }

             }
             j++;

         }
         return ans;
    }
};