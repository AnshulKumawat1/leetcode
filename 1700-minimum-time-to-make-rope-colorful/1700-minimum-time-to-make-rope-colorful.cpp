class Solution {
public:
   
    int minCost(string s, vector<int>& time) {
    int ans=0; stack<pair<char,int>>st; st.push({s[0],time[0]});
    for(int i=1;i<s.size();i++){
        char ch=st.top().first;
        int t=st.top().second;
        if(ch==s[i]){
            if(time[i]<t){ans+=time[i]; continue;}
            else {
               ans+=t; st.pop(); 
            }
        }
        st.push({s[i],time[i]});
    }
    return ans;
    }
};