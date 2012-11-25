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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        for (int i = lists.size() - 1; i >= 0; --i) {
            if (!lists[i]) lists.erase(lists.begin() + i);
        }
        if (lists.empty()) return NULL;
        ListNode *node = lists[0];
        int index = 0;
        for (int i = 1; i < lists.size(); ++i) {
            if (lists[i]->val < node->val) {
                node = lists[i];
                index = i;
            }
        }
        lists[index] = lists[index]->next;
        if (!lists[index]) lists.erase(lists.begin() + index);
        node->next = mergeKLists(lists);
        return node;
    }
};
