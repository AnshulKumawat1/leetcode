class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
          long long ans=0;
          multiset<int>s;
          for(auto it:skill) s.insert(it);
          int sum=(*s.begin())+(*s.rbegin());
          sort(skill.begin(),skill.end()); int n=skill.size();
          for(int i=0;i<skill.size()/2;i++){
            if(skill[i]+skill[n-i-1]!=sum) return -1;
            else ans+=skill[i]*1LL*skill[n-i-1];
          }
          return ans;
        

    }
};