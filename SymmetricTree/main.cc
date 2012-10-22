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
    bool isSymmetric_(TreeNode *a, TreeNode *b) {
        if (!a && !b) return true;
        else if (!a && b) return false;
        else if (a && !b) return false;
        return a->val == b->val &&
               isSymmetric_(a->left, b->right) &&
               isSymmetric_(a->right, b->left);
    }

    bool isSymmetric(TreeNode *root) {
        return isSymmetric_(root, root);
    }
};
