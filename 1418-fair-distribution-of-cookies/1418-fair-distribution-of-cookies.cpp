class Solution {
public:
       
       int solve(vector<int>& cookies, int ind,vector<int>&child){
               if(ind==cookies.size()){
                   return *max_element( child.begin(),child.end());
               }
                int cookie=cookies[ind]; int mini=10e8;
           for(int i=0;i<child.size();i++){
               child[i]+=cookie;
              mini=min(mini,  solve(cookies,ind+1,child));
                child[i]-=cookie;
           }

       return mini;

        }
    int distributeCookies(vector<int>& cookies, int k) {
         
           vector<int>child(k);
         return  solve(cookies,0,child);
          
        
    }
};