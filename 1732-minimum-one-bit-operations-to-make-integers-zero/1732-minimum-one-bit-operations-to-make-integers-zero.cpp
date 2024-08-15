class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long>f(32,0);
        f[0]=1;
        for(int i=1;i<=31;i++){
         f[i]=2*f[i-1]+1;
        }
        int result=0;int sign=1;
       for(int i=30;i>=0;i--){
         int b= n&(1<<i);
         if(b==0)continue;
         if(sign==1) {result+=f[i]; sign=0;}
         else {result-=f[i]; sign=1;}

         
       }
       return result;
    }
};