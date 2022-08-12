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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *a_ptr = list1, *a_ptr_prev = nullptr;
        while(a--) {
            a_ptr_prev = a_ptr;
            a_ptr = a_ptr->next;
        }
        
        ListNode *b_ptr = list1;
        while(b--) {
            b_ptr = b_ptr->next;
        }
        
        ListNode *head = list1, *node = nullptr;
        // a is the head
        if(a_ptr_prev == nullptr) {
            head = list2;
            node = head;
        } else
        {
            a_ptr_prev->next = list2;
            node = a_ptr_prev;
        }

        while(node->next) {
            node = node->next;
        }
        node->next = b_ptr->next;
        
        return head;
    }
};
