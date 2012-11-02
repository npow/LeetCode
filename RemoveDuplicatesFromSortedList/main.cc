/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates(head, NULL);
    }
    ListNode *deleteDuplicates(ListNode *head, ListNode *prev) {
        if (!head) return NULL;
        if (prev && prev->val == head->val) {
            return deleteDuplicates(head->next, head);
        } else {
            head->next = deleteDuplicates(head->next, head);
            return head;
        }
    }
};
