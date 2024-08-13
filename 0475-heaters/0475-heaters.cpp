class Solution {
public:
   bool solve(vector<int>&ho,vector<int>&h,int mid){
               int j=0; 
        for(int i=0;i<h.size();i++){
             int start=h[i]-mid;
              int end=h[i]+mid;
            while(j<ho.size() && ho[j]>=start && ho[j]<=end ){
                j++;
            }
        }
        if(j>=ho.size() ) return true;
        return false;
   }
    int findRadius(vector<int>& ho, vector<int>& heat) {
          sort(ho.begin(),ho.end()); sort(heat.begin(),heat.end());
         int l=0,h=1e9;
         while(h>=l){
            int mid=(l+h)>>1;
            if(solve(ho,heat,mid)==true){
                 h=mid-1;
            }
            else l=mid+1;
         }
         return l;
    }
};