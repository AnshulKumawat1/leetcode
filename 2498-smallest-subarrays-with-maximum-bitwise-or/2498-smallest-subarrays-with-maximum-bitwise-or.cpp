class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
           vector<int>ans;
           vector<queue<int>>bit(31);
           for(int i=0;i<nums.size();i++){
              for(int j=0;j<31;j++){
                int b=(nums[i]&(1<<j));
                if(b) bit[j].push(i);
              }
           }
           for(int i=0;i<nums.size();i++){
              int maxi=i;
               for(auto & q:bit){
                  while(q.size()>0 && i>q.front()) q.pop();
                  if(q.size()>0) maxi=max(maxi,q.front());
                 
               }
               ans.push_back(maxi-i+1);
           }
           return ans;
           
    }
};