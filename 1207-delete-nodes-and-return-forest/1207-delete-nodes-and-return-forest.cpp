/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root,  vector<TreeNode*> &ans, unordered_set<int>&s){
        if(root==nullptr) return nullptr;
         root->left =solve(root->left,ans,s);
         root->right =solve(root->right,ans,s);
         if(s.find(root->val)!=s.end()){
         if(root->left)  ans.push_back(root->left);
          if(root->right)  ans.push_back(root->right);
            root->left=nullptr; root->right=nullptr;
            return nullptr;
         } else return root;

     }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& d) {
         vector<TreeNode*> ans;
         unordered_set<int>s;
         for(auto it:d)s.insert(it);
         solve(root,ans,s);
         if(s.find(root->val)==s.end()) ans.push_back(root);
         return ans;
    }
};