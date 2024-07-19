class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        long long  i=0,j=0,ans=0,sum=0;
        while(j<nums.size()){
             
              if((sum & nums[j])>0 ){
                  while((sum &nums[j])>0 ){
                      sum^=nums[i];
                      i++;
                  }
              }
                sum|=nums[j];
               ans=max(ans,j-i+1);
                j++;

        }
        return ans;

    }
};