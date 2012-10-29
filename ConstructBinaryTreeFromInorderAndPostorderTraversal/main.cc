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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) return NULL;
        TreeNode *root = new TreeNode(postorder.back());
        postorder.pop_back();
        int i;
        for (i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == root->val) break;
        }
        vector<int> left = vector<int>(inorder.begin(), inorder.begin() + i);
        vector<int> right = vector<int>(inorder.begin() + i + 1, inorder.end());
        root->right = buildTree(right, postorder);
        root->left = buildTree(left, postorder);
        return root;
    }
};
