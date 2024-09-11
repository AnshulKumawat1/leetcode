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
#include <queue>
#include <tuple>
#include <limits> // for INT_MIN and INT_MAX

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true; // An empty tree is a valid BST

        std::queue<std::tuple<TreeNode*, long long, long long>> q;
        q.emplace(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());

        while (!q.empty()) {
            auto [node, mini, maxi] = q.front();
            q.pop();

            if (node->val <= mini || node->val >= maxi) return false;

            if (node->left != nullptr) {
                q.emplace(node->left, mini, node->val);
            }
            if (node->right != nullptr) {
                q.emplace(node->right, node->val, maxi);
            }
        }

        return true;
    }
};
