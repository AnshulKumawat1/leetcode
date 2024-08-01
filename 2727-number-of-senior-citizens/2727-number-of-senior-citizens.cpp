class Solution {
public:
    int countSeniors(vector<string>& s) {
         int ans=0;
         for(auto it: s){
              string a=  it.substr(11,2);
             if(stoi(a)>60) ans++;
         }
        return ans;
    }
};