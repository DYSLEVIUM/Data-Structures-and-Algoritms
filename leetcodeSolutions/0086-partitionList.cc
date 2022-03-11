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
    ListNode* partition(ListNode* head, int x) {
      if(!head || !head->next) return head;
      
      ListNode *before = new ListNode;
      ListNode *before_head = before;
      
      ListNode *after = new ListNode;
      ListNode *after_head = after;
      
      while(head){
        if(head->val < x){
          before->next = head;
          before = before->next;
        } else {
          after->next = head;
          after = after->next;
        }
        
        head = head->next;
      }
      after->next = nullptr;
      before->next = after_head->next;
      
      return before_head->next;
      
//       vector<int> less_x, greater_x;
//       while(head) {
//         if(head->val < x) less_x.push_back(head->val);
//         else greater_x.push_back(head->val);
//         head = head->next;
//       }
      
//       ListNode *new_head = new ListNode;
//       ListNode *node = new_head;
//       for(int i = 0; i < less_x.size(); ++i) {
//         node->next = new ListNode(less_x[i]);
//         node = node->next;
//       }
        
//       for(int i = 0; i < greater_x.size(); ++i) {
//         node->next = new ListNode(greater_x[i]);
//         node = node->next;
//       }
        
//       return new_head->next;
    }
};
