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
      ListNode *node = head, *prev_node = nullptr;
      while(node && node->next) {
        ListNode *next_node = node->next;
        if(next_node && node->val == next_node->val){
          while(next_node && node->val == next_node->val){
            ListNode *temp = next_node;
            
            next_node = next_node->next;
            node->next = next_node;
            
            delete temp;
            temp = nullptr;
          }
          delete node;
          node = next_node;
          
          if(next_node) next_node = node->next;
          if(prev_node) prev_node->next = node; //  if the repeated nodes are not at first
          else head = node; //  if there was no prev_node, it means that we were on the head so the head will change
          
        }else{
          prev_node = node;
          node = node->next;
        }
      }
      
      return head;
    }
};
