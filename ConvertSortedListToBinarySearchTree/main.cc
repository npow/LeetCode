/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode *h = head;
        int num = 0;
        while (h) {
            h = h->next;
            num++;
        }
        return sortedListToBST(head, 0, num-1);
    }
    TreeNode *sortedListToBST(ListNode *&head, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *left = sortedListToBST(head, start, mid-1);
        TreeNode *root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = sortedListToBST(head, mid+1, end);
        return root;
    }
};
