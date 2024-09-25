class Solution {
public:
    bool find132pattern(vector<int>& nums) {
         multiset<int>l;
         multiset<int>r;
         for(int i=1;i<nums.size();i++) r.insert(nums[i]);
         l.insert(nums[0]);
         int n=nums.size();
         for(int i=1;i<=n-2;i++){
          r.erase(r.find(nums[i]));
          int a=*l.begin();
          if(a>=nums[i]) {l.insert(nums[i]);continue;}
          else{
            auto it=r.lower_bound(nums[i]);
            if(it!=r.begin()) {
                it--;
              int ak=*it;
              if(ak>a) return true;  
            }
          }
          l.insert(nums[i]);
         }
         return false;
    }
};