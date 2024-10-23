class Solution {
public:
  int  solve(int a,int b){

    return a+b;

   }
    string removeDuplicateLetters(string s) {
        set<char>se;
        string ans;
        vector<int>count(26,0);
        for(auto it:s) count[it-'a']++;
        for(int i=0;i<s.size();i++){
             if(se.find(s[i])!=se.end()){
             count[s[i]-'a']--;
                 continue; 
             }
             while(ans.size()>0 && ans.back()>s[i] && count[ans.back()-'a']>0){
                se.erase(ans.back());
                ans.pop_back(); 
             }
             se.insert(s[i]);
             count[s[i]-'a']--;
             ans+=s[i];
        
        }
        int c=solve(2,4);
        return ans;
    }
};