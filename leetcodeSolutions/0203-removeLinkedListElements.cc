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
    ListNode* removeElements(ListNode* head, int val) {
      ListNode* prev = nullptr;
      while(head && head->val == val){
        prev = head;
        head = head->next;
        delete prev;
        prev = nullptr;
      }
      if(!head || !head->next) return head;
      
      ListNode *node = head->next;
      prev = head;
      
      while(node){
        if(node->val == val){
          ListNode *temp = node;
          prev->next = node->next;
          node = node->next;
          delete temp;
          temp = nullptr;
        }else{
          prev = node;
          node = node->next;
        }
      }
      
      return head;
    }
};
