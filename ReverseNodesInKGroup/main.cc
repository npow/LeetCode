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
    ListNode *reverse(ListNode *head, ListNode *prev) {
      if (!head) return prev;
      ListNode *next = head->next;
      head->next = prev;
      return reverse(next, head);
    }
    ListNode *reverseKGroup(ListNode *head, int k, int i, ListNode *prev) {
        if (!head) return i < k ? reverse(prev, NULL) : prev;
        if (i == k) {
            ListNode *curr = prev;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = reverseKGroup(head, k, 0, NULL);
            return prev;
        } else {
            ListNode *next = head->next;
            head->next = prev;
            return reverseKGroup(next, k, i+1, head);
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        return reverseKGroup(head, k, 0, NULL);
    }
};
