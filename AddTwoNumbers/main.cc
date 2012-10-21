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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addTwoNumbersHelper(l1, l2, 0);
    }
    ListNode *addTwoNumbersHelper(ListNode *l1, ListNode *l2, int carry) {
        ListNode* node = NULL;
        if (!l1 && !l2) {
            if (carry) {
                node = new ListNode(carry);
                node->next = NULL;
            } else {
                return NULL;
            }
        } else {    
           int curr = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
           if (curr > 9) {
               carry = curr / 10;
               curr %= 10;
           } else {
               carry = 0;
           }
           node = new ListNode(curr);
           node->next = addTwoNumbersHelper((l1 ? l1->next : NULL), (l2 ? l2->next : NULL), carry);
        }
        return node;
    }
};
