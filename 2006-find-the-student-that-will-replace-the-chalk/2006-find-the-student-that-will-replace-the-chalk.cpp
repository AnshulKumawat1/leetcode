class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int ak) {
         long long k=ak;
      long long  int sum=0;
      for(auto it:chalk) sum+=it;
       long long   int t=(k*1ll)/sum; 
          k=k-(t*1ll*sum); 
          int cur=0;
          for(int i=0;i<chalk.size();i++){
            if(chalk[i]<=k){
                k-=chalk[i];
            }
            else return i;
          }
          return -1;
    }
};