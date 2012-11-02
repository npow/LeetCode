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
    ListNode *partition(ListNode *head, int x) {
        return partition(head, x, NULL, NULL);
    }
    ListNode *partition(ListNode *head, int x, ListNode *h, ListNode *t) {
        if (!head) return h;
        if (head->val < x) {
            head->next = partition(head->next, x, h, t);
            return head;
        } else {
            ListNode *next = head->next;
            if (t) {
                t->next = head;
                t = t->next;
            } else {
                h = t = head;
            }
            head->next = NULL;
            return partition(next, x, h, t);
        }
    }
};
