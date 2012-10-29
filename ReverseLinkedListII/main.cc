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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        return reverseBetween(head, m, n, 1, NULL);
    }
    ListNode *reverseBetween(ListNode *head, int m, int n, int i, ListNode *rev) {
        if (i < m) {
            head->next = reverseBetween(head->next, m, n, i+1, NULL);
            return head;
        } else if (m <= i && i <= n) {
            ListNode *next = head->next;
            head->next = rev;
            return reverseBetween(next, m, n, i+1, head);
        } else {
            ListNode *r = rev;
            while (rev->next) {
                rev = rev->next;
            }
            rev->next = head;
            return r;
        }
    }
};
