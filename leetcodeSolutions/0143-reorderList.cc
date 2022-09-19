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
    void reorderList(ListNode* head) {
      if(!head || !head->next) {
        return ;
      }
      
      auto middle_node = [](ListNode * const &head) {
        auto slow = head, fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
      };
      
      auto reverse = [](ListNode * &head){
        ListNode *prev = nullptr;
        while(head) {
          ListNode *next = head->next;
          head->next = prev;
          prev = head;
          head = next;
        }
        return prev;
      };
      
      auto mid = middle_node(head);
      auto le = head->next, ri = reverse(mid);
      for(int i = 0; le != ri; ++i, head = head->next) {
        if(i & 1) {
          head->next = le;
          le = le->next;
        } else {
          head->next = ri;
          ri = ri->next;
        }
      }
    }
};
