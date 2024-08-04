class Solution {
public:
    string breakPalindrome(string s) {
        string r=s;
       if(s.size()==1) return ""; bool flag=true;
       for(int i=0;i<s.size();i++){
        if(s[i]!='a') {s[i]='a';  flag=false; break;}
       }  
       if(flag==true)s[s.size()-1]='b';
       bool fl=true;
       int n=s.size();
       for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[n-i-1]){
            fl=false; break;
        }
       }
       if(fl==true) {r[s.size()-1]='b'; return r;}
       return s;
    }
};