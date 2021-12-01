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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val;
        int carry = 0;
        
        ListNode* node = new ListNode();
        ListNode* head = node;
        
        while(l1!=nullptr && l2!=nullptr){
            val = l1->val+l2->val+carry;
            node->val = val%10;
            carry=val/10;
            
            if(l1->next!=nullptr || l2->next!=nullptr || carry) {
                node->next = new ListNode();
                node = node->next;            
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=nullptr){
            val = l1->val+carry;
            node->val = val%10;
            carry = val/10;
            
            if(l1->next!=nullptr || carry) {
                node->next = new ListNode();
                node = node->next;                
            }
            
            l1 = l1->next;
        }
        
        while(l2!=nullptr){
            val = l2->val+carry;
            node->val = val%10;
            carry = val/10;
            
            if(l2->next!=nullptr || carry) {
                node->next = new ListNode();                
                node = node->next;
            }
            
            l2 = l2->next;
        }
        
        if(carry) node->val = carry;
        
        return head;
    }
};
