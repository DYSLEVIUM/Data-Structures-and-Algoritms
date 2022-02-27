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
    ListNode* reverseList(ListNode* head) {
      if(!head || !head->next) return head;

      //  recursive
//       ListNode *rest = reverseList(head->next);
      
//       ListNode* prev_node = head->next;
      
//       prev_node->next = head;
//       head->next = nullptr;
      
//       return rest;
      
      //  iterative
      ListNode *prev_node = nullptr, *curr_node = head, *next_node = nullptr;
      while(curr_node){
        next_node = curr_node->next;  //  saving the next_node, so it isn't overwritten
        curr_node->next = prev_node; //  changing the order
        
        //  changing the values for next iteration
        prev_node = curr_node;
        curr_node = next_node;
      }
      
      return prev_node;
    }
};
