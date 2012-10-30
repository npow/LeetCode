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
     static bool isEmptyVec(vector<int>& v) {
        return v.empty();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        return pathSum(root, sum, vector<int>());
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum, vector<int> path) {
        vector<vector<int> > res = vector<vector<int> >();
        if (!root) return res;
        
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            res.push_back(path);
            return res;
        }
        vector<vector<int> > left = pathSum(root->left, sum - root->val, path);
        vector<vector<int> > right = pathSum(root->right, sum - root->val, path);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        
        sort(res.begin(), res.end());
        res.erase(remove_if(res.begin(), res.end(), Solution::isEmptyVec), res.end());
        return res;
    }
};

