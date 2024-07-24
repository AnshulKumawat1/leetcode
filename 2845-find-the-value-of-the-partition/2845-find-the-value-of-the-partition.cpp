class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            ans=min(ans,nums[i+1]-nums[i]);
        }
        return ans;
    }
};