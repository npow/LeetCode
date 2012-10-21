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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        deque<TreeNode*> Q;
        Q.push_back(root);
        int level = 0;
        while (!Q.empty()) {
            level++;
            vector<int> v;
            deque<TreeNode*> tmpQ;
            while (!Q.empty()) {
                TreeNode* node = Q.front();
                Q.pop_front();
                if (node) {
                    tmpQ.push_back(node->left);
                    tmpQ.push_back(node->right);
                    v.push_back(node->val);
                }
            }
            Q = tmpQ;
            if (v.size() > 0) {
                if (level % 2 == 0) {
                    reverse(v.begin(), v.end());
                }
                res.push_back(v);
            }
        }
        return res;
    }
};
