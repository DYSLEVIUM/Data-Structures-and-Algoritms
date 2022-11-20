/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;

        while(head && head->val == val) head = head->next;

        ListNode * node = head, * prev = nullptr;
        while(node) {
            while(node && node->val == val) node = node->next;
            if(prev) prev->next = node;
            prev = node;
            if(node) node = node->next;
        }

        return head;
    }
};
