class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        multiset<int>s;
        for(auto it:nums) s.insert(it);
        sort(nums.begin(),nums.end()); int cnt=0;
        for(int i=0;i<nums.size();i++){
           auto it=s.upper_bound(nums[i]);
           if(it!=s.end()){ s.erase(it); cnt++;}
        }
        return cnt;
    }
};