class Solution {
public:
   long long dp[100006][5];
    long long solve(vector<int>& a, vector<int>& b,int i,int j){
     if(i>=a.size()) return 0;
     if(j>=b.size()) return -1e17;
     if(dp[j][i]!=-1) return dp[j][i];

     long long take=a[i]*1LL*b[j]+solve(a,b,i+1,j+1);
     long long notake=solve(a,b,i,j+1);

     return dp[j][i]= max(take,notake);

    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        memset(dp,-1,sizeof(dp));
      long long ans=solve(a,b,0,0);  
      return ans;
    }
};