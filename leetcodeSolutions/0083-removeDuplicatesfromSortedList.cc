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
    ListNode* deleteDuplicates(ListNode* head) {
      if(!head) return nullptr;
      
      ListNode* node = head;
      
      while(node){
        ListNode* next_node = node->next;
        
        while(next_node && node->val == next_node->val){
          ListNode* temp = next_node;
          next_node = next_node->next;
          
          delete temp;  //  removing the unnecessary node  
          temp = nullptr;
        }
        
        node->next = next_node;
        node = next_node;
      }
      
      return head;
    }
};
