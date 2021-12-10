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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        
        int length = 0;
        
        while(node) node = node->next, ++length;
        
        if(n == length) return head->next;
        
        node = head;
        
        n = length - n - 1;
        
        while(n > 0) node = node->next, --n;
        
        node->next = node->next->next;

        return head;
    }
};
