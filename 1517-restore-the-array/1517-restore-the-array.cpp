class Solution {
public:
           int dp[100005];
            int mod =1e9+7;
       int solve(string &s ,int k,int ind){


         if(ind==s.size()) return 1;
           if(dp[ind]!=-1) return dp[ind];
              int l=0;
         for(int i=ind;i<s.size();i++){
          string a= s.substr(ind,i-ind+1);
          if(a[0]=='0') break;
          if(stoll(a)>k) break;

          int an=solve(s,k,i+1);
           l=((l%mod)+(an%mod))%mod;


         }


         return dp[ind]= l;


       }
    int numberOfArrays(string s, int k) {
           memset(dp,-1,sizeof(dp));
         return solve(s,k,0);
    }
};