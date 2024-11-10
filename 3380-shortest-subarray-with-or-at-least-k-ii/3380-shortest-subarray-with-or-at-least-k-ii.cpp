class Solution {
public:
      int find(vector<int>&bits){
        int ak=0;
        for(int k=31;k>=0;k--){
            int b=bits[k];
            if(b>=1) ak=ak|(1<<k);
        }
        return ak;
      }
    int minimumSubarrayLength(vector<int>& nums, int t) {
        vector<int>bits(32,0);
         int i=0,j=0,ans=1e9;
         while(j<nums.size()){

            for(int k=31;k>=0;k--){
                int b=nums[j]&(1<<k);
                if(b) bits[k]++;
            }
            //   cout<<find(bits)<<endl;
            while(i<=j && find(bits)>=t){
                ans=min(j-i+1,ans);
                for(int k=31;k>=0;k--){
                int b=nums[i]&(1<<k);
                if(b) bits[k]--;
                }
                i++;
            }

            j++;

         }
         if(ans==1e9) return -1;
         return ans;

    }
};