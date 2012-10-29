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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST_(num, 0, num.size()-1);
    }
    TreeNode *sortedArrayToBST_(vector<int> &num, int i, int j) {
        if (i > j) return NULL;
        int mid = (i + j) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST_(num, i, mid-1);
        root->right = sortedArrayToBST_(num, mid+1, j);
        return root;
    }
};
