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
    TreeNode *flatten_(TreeNode *root) {
        if (!root) return NULL;
        TreeNode *left = flatten_(root->left);
        TreeNode *right = flatten_(root->right);
        root->left = NULL;
        root->right = left;
        TreeNode *r = root;
        if (r->right) {
            do {
                r = r->right;
                if (!r->right) {
                    r->right = right;
                    break;
                }
            } while (r->right);
        } else {
            r->right = right;
        }

        return root;
    }
    void flatten(TreeNode *root) {
        flatten_(root);
    }
};
