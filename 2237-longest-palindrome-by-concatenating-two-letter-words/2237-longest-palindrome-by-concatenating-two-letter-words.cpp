class Solution {
public:
   
    int longestPalindrome(vector<string>& words) {
         map<string,int>m; int ans=0; set<string >s;
        for(auto it:words) {
          m[it]++; s.insert(it);
        }
        bool flag=true; int ak=0;
        for(auto it:s){
            string a; a.push_back(it[1]); a.push_back(it[0]);

            if(m.find(a)!=m.end() && it[0]!=it[1]){
             ans+=2*min(m[a],m[it]); continue;
            }
            else if(it[0]==it[1] && m[it]==1 && flag==true){
                flag=false; ans+=2;
            }
           else if(it[0]==it[1]  && m[it]>1){
               if(m[it]%2==0) ans+=2*m[it];
               else {ans+= 2*(m[it]-1); ak=1;}
           }
             
        }
        if(flag==true && ak==1){
 ans+=2;
        }

        
        
        return ans;
    }
};