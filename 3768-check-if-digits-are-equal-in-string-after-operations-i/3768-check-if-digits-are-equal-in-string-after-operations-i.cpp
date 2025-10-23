class Solution {
public:
    bool hasSameDigits(string s) {
           while(s.size()>2){
             string ak;
             for(int i=0;i<s.size()-1;i++){
                int a=(s[i]-'0')+(s[i+1]-'0');
                a=a%10;
                ak=ak+to_string(a);
             }
             s=ak;

           }
           if(s[0]==s[1]) return true;
           return 0;

    }
};