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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *tmp = head->next,
                 *tmpNext = tmp->next;
        tmp->next = head;
        head->next = swapPairs(tmpNext);
        return tmp;
    }
};
