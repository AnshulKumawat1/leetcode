class Solution {
public:
    vector<int> sortJumbled(vector<int>& m, vector<int>& nums) {
        vector<pair<int,int>>ans; 
        for(int i=0;i<nums.size();i++){
             int a=nums[i]; int n=0; int mul=1;
             if(nums[i]==0){
                  ans.push_back({m[0],i}); continue;
             }
             while(a>0){
                int r= a%10;
                n=m[r]*mul+n;
                mul=mul*10;
                 a=a/10;
             }

          ans.push_back({n,i});
        }
        sort(ans.begin(),ans.end());
        vector<int>ak;
        for(auto it:ans){
            ak.push_back(nums[it.second]);
        }
        return ak;
    }
};