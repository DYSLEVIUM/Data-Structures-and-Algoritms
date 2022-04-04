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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        int total_length = 0;
        ListNode *temp_node = head;
        while(temp_node) {
            temp_node = temp_node->next;
            ++total_length;
        }
        
        ListNode *first_prev = nullptr, *first_node = head;
        int temp_k = k - 1;
        while(temp_k--) {
            first_prev = first_node;
            first_node = first_node->next;
        }
        
        ListNode *second_prev = nullptr, *second_node = head;
        temp_k = total_length - k;
        while(temp_k--) {
            second_prev = second_node;
            second_node = second_node->next;
        }
        swap(first_node->val, second_node->val);
        
        return head;
    }
};
