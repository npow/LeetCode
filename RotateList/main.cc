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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        ListNode *h = head, *n = head;
        int numNodes = 1;
        while (h->next) {
            numNodes++;
            h = h->next;
        }
        k %= numNodes;
        if (!k) return head;
        for (int i = 0; i < k; ++i) {
            n = n->next;
        }
        h = head;
        while (n->next) {
            h = h->next;
            n = n->next;
        }
        ListNode *tmp = h->next;
        h->next = NULL;
        n->next = head;
        return tmp;
    }
};
