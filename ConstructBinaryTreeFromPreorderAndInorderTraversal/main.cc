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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) return NULL;
        TreeNode *root = new TreeNode(preorder.front());
        preorder.erase(preorder.begin());
        int i;
        for (i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == root->val) {
                break;
            }
        }
        vector<int> left = vector<int>(inorder.begin(), inorder.begin() + i);
        vector<int> right = vector<int>(inorder.begin() + i + 1, inorder.end());
        root->left = buildTree(preorder, left);
        root->right = buildTree(preorder, right);
        return root;
    }
};
