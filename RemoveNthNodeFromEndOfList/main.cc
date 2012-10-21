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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *A = head,
                 *B = head,
                 *prevA = NULL;
        for (int i = 0; B && i < n; ++i) {
            B = B->next;
        }
        while (B) {
            B = B->next;
            prevA = A;
            A = A->next;
        }
        if (prevA) {
            prevA->next = A->next;
            return head;
        } else {
            return A->next;
        }
    }
};
