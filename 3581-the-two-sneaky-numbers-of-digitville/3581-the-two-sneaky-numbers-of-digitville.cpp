class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
            if(m[it]>1) ans.push_back(it);
        }
        return ans;
    }
};