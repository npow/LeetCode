/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return abs(leftHeight - rightHeight) < 2 &&
               isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
