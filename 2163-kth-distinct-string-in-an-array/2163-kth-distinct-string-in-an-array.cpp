class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
         map<string ,int>m;
         for(auto it:arr) m[it]++;
         int a=k;k--;
         for(auto it:arr){
           if(m[it]==1) {
            if(k==0) return it;
            else k--;
           }
           
         }
         return "";
    }
};