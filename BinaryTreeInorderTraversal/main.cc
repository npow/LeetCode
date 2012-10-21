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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        set<TreeNode*> visited;
        s.push(root);
        while (!s.empty()) {
            TreeNode* top = s.top();
            if (top) {
                if (visited.find(top) == visited.end()) {
                    s.push(top->left);
                } else {
                    res.push_back(top->val);
                    s.pop();
                    s.push(top->right);
                }
            } else {
                s.pop();
                if (!s.empty()) {
                    visited.insert(s.top());
                }
            }
        }
        return res;
    }
};
