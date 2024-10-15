class Solution {
public:
    long long minimumSteps(string s) {
       long long ans=0;
       int i=0,j=s.size()-1;
       while(j>i){
        if(s[i]=='0'){ i++; continue; }
        if(s[j]=='1') {j--; continue;}
         swap(s[i],s[j]);
         ans+=j-i; i++;j--;
       }
    //    cout<<s<<" ";
       return ans;
    }
};