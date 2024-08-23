class Solution {
public:
    
    int longestValidParentheses(string s) {
         stack<pair<char,int>>st; int ans=0;
         for(int i=0;i<s.size();i++){
             if(s[i]=='(') st.push({'(',i});
             else{
                if(st.size()==0){
                    st.push({')',i}); continue;
                }
                if(st.top().first=='('){
                     st.pop();
                   if(st.size()>0)  ans=max(ans,i-st.top().second);
                   else ans=max(ans,i+1);
                }
                else{
                     st.push({')',i}); 
                }
                
             }
         }
         return ans;
    }
};