class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;int sum=0;int n=nums.size(); set<vector<int>>s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int a= sum-nums[i]; 
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==a ){
                    if( k==n-1 || nums[k]!=nums[k+1] ){
                     s.insert({nums[i],nums[j],nums[k]});
                     }
                     j++;k--;}

               else if(nums[j]+nums[k]>a) k--;
               else if(nums[j]+nums[k]<a) j++;
            }
        }
       for(auto x:s) ans.push_back(x);

       return ans;
    }
};