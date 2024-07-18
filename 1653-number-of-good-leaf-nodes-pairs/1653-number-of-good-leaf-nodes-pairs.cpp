// //**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
      void solve(TreeNode* root,  unordered_map<TreeNode*,vector<TreeNode*>>&m,set<TreeNode*>&leaf){
       if(root->left==nullptr && root->right==nullptr){
            leaf.insert(root); return ;
       }
      if(root->left){
        m[root->left].push_back(root);
        m[root].push_back(root->left);
        solve(root->left,m,leaf);
      }
      if(root->right){
         m[root->right].push_back(root);
         m[root].push_back(root->right);
        solve(root->right,m,leaf);
      }

      }
    
    int countPairs(TreeNode* root, int distance) {
         set<TreeNode*>leaf;
         if(distance<=1) return 0;
         unordered_map<TreeNode*,vector<TreeNode*>>m;
         solve(root,m,leaf); 
         int ans=0;
         for(auto & it:leaf){
            TreeNode*src=it;
           queue<tuple<TreeNode*,int>>q;
           q.emplace(src,0);
            set<TreeNode*>vis; vis.insert(src);
           while(q.size()>0){
             auto[node,steps]=q.front(); q.pop();
             if(steps>distance) continue;
             if(leaf.find(node)!=leaf.end() && src!=node) {
                ans++;
             }
             for(auto it:m[node]){
                if(vis.find(it)==vis.end()){
                   vis.insert(it); q.emplace(it,steps+1);
                }
             }
          }
         }
         return (ans)/2;

    }
};