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
    ListNode* insertionSortList(ListNode* head) {
      auto dummy = new ListNode(INT_MIN, head);
      auto curr_prev = head, curr = head->next;
      while(curr) {
        auto j_prev = dummy, j = j_prev->next, curr_next = curr->next;
        
        // at correct position
        if(curr->val > curr_prev->val) {
          curr_prev = curr;
        } else {
          while(j->val < curr->val) {
            j_prev = j, j = j->next;
          }
          curr->next = j;
          j_prev->next = curr;
          curr_prev->next = curr_next;
        }
        
        curr = curr_next;
      }
      
      return dummy->next;
    }
};

class Solution2 {
public:
    ListNode* insertionSortList(ListNode* head) {
      for(auto cur = head; cur; cur = cur->next) {
        for(auto j = head; j != cur; j = j->next) {
          if(j->val > cur->val) {
            swap(j->val, cur->val);
          }
        }
      }
      return head;
    }
};
