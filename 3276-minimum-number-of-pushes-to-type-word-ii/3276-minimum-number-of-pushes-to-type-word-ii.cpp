class Solution {
public:
    int minimumPushes(string word) {
          int count[26]={0}; int ans=0;
          for(int i=0;i<word.size();i++){
             
              count[word[i]-'a']++;
          }
            priority_queue<pair<int,char>>p;
           for(int i=0;i<26;i++){
            if(count[i]>0) p.push({count[i],i+'a'});
           }
            int a=0; int c[26]={0};
           while(p.size()>0){ a++;
               auto it=p.top(); p.pop();
               if(a<=8) c[it.second-'a']=1;
               else if(a>8 && a<=16) c[it.second-'a']=2;
               else if(a>16 && a<=24) c[it.second-'a']=3;
               else c[it.second-'a']=4;
               
           }
           for(int i=0;i<word.size();i++){
             
              ans+=c[word[i]-'a'];
          }

           return ans;

    }
};