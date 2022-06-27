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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(!head){
        return nullptr;
      }
      
      ListNode *prev = nullptr, *curr = head;
      while(left > 1) {
        prev = curr;
        curr = curr->next;
        --left;
        --right;
      }
      
      ListNode *con = prev, *tail = curr;
      
      ListNode *next_node = nullptr;
      while(right) {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
        
        --right;
      }
      
      //  fixing the end points
      if (con) {
          con->next = prev;
      } else {
          head = prev;
      }
      tail->next = next_node;

      return head;
    }
};
