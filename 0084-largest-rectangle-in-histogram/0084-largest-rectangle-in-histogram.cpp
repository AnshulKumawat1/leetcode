class Solution {
public:
    vector<int>left(vector<int>&h){
     
      vector<int>ans; int n=h.size();
      ans.push_back(-1); stack<int>s; s.push(0);
      for(int i=1;i<n;i++){
         while(s.size()>0 && h[s.top()]>=h[i]){
            s.pop();
         }
         if(s.size()==0) ans.push_back(-1);
         else ans.push_back(s.top());
         s.push(i);
      } 

    return ans;
    }
    vector<int>right(vector<int>&h){

    stack<int>s; vector<int>ans; int n=h.size();
    ans.push_back(n); 
      s.push(h.size()-1);
    for(int i=n-2;i>=0;i--){
       while(s.size()>0 && h[s.top()]>=h[i] ){
        s.pop();
       }
       if(s.size()==0) ans.push_back(n);
       else ans.push_back(s.top());
       s.push(i);
   }


    reverse(ans.begin(),ans.end());
    return ans;
    }
    int largestRectangleArea(vector<int>& heights) {

        vector<int>l=left(heights);
        vector<int>r=right(heights);

    for(auto it:l) cout<<it<<" "; cout<<endl;
    for(auto it:r) cout<<it<<" ";
    int ans=0; int n=heights.size();
     for(int i=0;i<n;i++){
     
          int range=(r[i]-l[i]-1);
           ans=max(ans,heights[i]*range);
     
     }

      return ans;




    }
};