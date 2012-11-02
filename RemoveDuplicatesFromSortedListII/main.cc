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
        if (!head) return NULL;
        ListNode *h = head->next;
        if (h) {
            if (h->val == head->val) {
                do {
                    h = h->next;
                } while (h && h->val == head->val);
                return deleteDuplicates(h);
            } else {
                head->next = deleteDuplicates(head->next);
                return head;
            }
        } else {
            return head;
        }
    }
};
