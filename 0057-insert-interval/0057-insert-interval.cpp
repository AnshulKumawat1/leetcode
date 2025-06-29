class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& n) {

         vector<vector<int>>ans;
         arr.push_back(n);
        sort(arr.begin(),arr.end());

       // ls=1 le=3.  cs
        ans.push_back({arr[0][0],arr[0][1]});
        for(int i=1;i<arr.size();i++){
         int ls= ans[ans.size()-1][0];
         int le=ans[ans.size()-1][1];
         int cs=arr[i][0];
         int ce=arr[i][1];
         if(cs>le){
            ans.push_back({cs,ce});
         }
         else{
            int newend=max(ce,le);
            ans.pop_back();
            ans.push_back({ls,newend});
         }
         
        }
        return ans; 
    }
};