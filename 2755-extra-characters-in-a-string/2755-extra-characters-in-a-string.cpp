class Solution {
public:
            int dp[52];
      int solve(string s, unordered_set<string>&se,int ind){
           if(ind==s.size()){
               return 0;
           }
        if(dp[ind]!=-1) return dp[ind];
             int p=1e8; int mx=1e9;
        for(int i=ind,j=ind;i<s.size();i++){
          string pre=s.substr(ind,i-ind+1);
           int cx=0;
           if(se.find(pre)==se.end()) cx=pre.size();
           else cx=0;
                
              p=solve(s,se,i+1);   
              int tx=cx+p;
              mx=min(tx,mx);


           }


       
         return dp[ind]= mx;

      }

     
    int minExtraChar(string s, vector<string>& d) {
      memset(dp,-1,sizeof(dp));
        unordered_set<string>se;
        for(auto it:d){
            se.insert(it);
        }
         return solve(s,se,0);
    }
};