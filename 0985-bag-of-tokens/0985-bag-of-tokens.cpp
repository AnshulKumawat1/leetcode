class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
         sort(tokens.begin(),tokens.end());
         int ans=0,cnt=0;
         int i=0,j=tokens.size()-1;
         while(j>=i){
           
           if(power>=tokens[i])
           {
            cnt++; power-=tokens[i]; i++;  
           }
           else{
            if(cnt<=0) break;
             power+=tokens[j]; cnt--; j--; 
           }
           cout<<cnt<<" ";
           ans=max(cnt,ans); 
         }
         return ans;
    }
};