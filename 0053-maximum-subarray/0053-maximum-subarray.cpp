class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int ans=0, maxi=0; int mini=-10e8,count=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>0) count++;
                mini=max(nums[i],mini);
            }
            if(count==0) return mini;
         for(int i=0;i<nums.size();i++){
                ans+=nums[i];
                maxi=max(maxi,ans);
                if(ans<0) ans=0;

                cout<<ans;
         }
         return maxi;
    }
};