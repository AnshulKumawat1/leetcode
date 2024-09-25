class Solution {
public:
  struct trinode{
    int cp;
    trinode*children[26];
      trinode(){
        for(int i=0;i<26;i++){
        cp=0;
        children[i]=NULL;
    }
      }

 };

 trinode*root= new trinode();
  void insert(string &w){
    trinode*crawler=root;
     for(int i=0;i<w.size();i++){
        int ind=w[i]-'a';
        if(crawler->children[ind]==NULL){
            crawler->children[ind]=new trinode();
        }
         crawler= crawler->children[ind];
         crawler->cp++;
    }
 }

int find(string w){
     trinode*crawler=root; int ans=0;
     for(int i=0;i<w.size();i++){
        int ind=w[i]-'a';
        crawler=crawler->children[ind];
        ans+=crawler->cp;
           
    }
    return ans;
}


   vector<int> sumPrefixScores(vector<string>& words) {

       for(auto it:words){
          insert(it);
       }
      vector<int>ans;
       for(auto it:words){
         ans.push_back(find(it));
       }
     return ans;
    }
};