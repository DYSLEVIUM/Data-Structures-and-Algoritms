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
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head || !head->next) return head;
      
      int len = 1;
      ListNode* node = head;
      while(node->next){
        ++len;
        node = node->next;
      }
      node->next = head;
      
      k %= len;
      int temp_len = len - k - 1;
      node = head;
      
      while(temp_len--){
        node = node->next;
      }
      ListNode* new_head = node->next;
      node->next = nullptr;
      
      return new_head;
    }
};
