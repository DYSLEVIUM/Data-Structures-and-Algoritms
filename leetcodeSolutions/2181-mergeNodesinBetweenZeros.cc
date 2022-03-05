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
    ListNode* mergeNodes(ListNode* head) {
      ListNode *new_head = head->next;
      
      //  removing the first 0
      delete head;
      head = nullptr;
      
      ListNode *node = new_head;      
      while(node){
        ListNode* next_node = node->next;
        while(next_node->val != 0){
          ListNode* temp = next_node;
          
          node->val += next_node->val;
          next_node = next_node->next;
          
          delete temp;
          temp = nullptr;
        }
        //  linking to the next of 0
        node->next = next_node->next;
        
        node = next_node->next; //  updating for the next iteration
        
        //  deleting this 0
        delete next_node;
        next_node = nullptr;
      }

      return new_head;
    }
};
