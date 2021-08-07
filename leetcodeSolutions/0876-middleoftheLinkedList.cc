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
    ListNode* middleNode(ListNode* head) {
      //  approach 1
//       int len = 0;
      
//       ListNode* te = head;
      
//       while(te!=nullptr){
//         te=te->next;
//         ++len;
//       }
      
//       len>>=1;
      
//       while(len){
//         head=head->next;
//         --len;
//       }
      
//       return head;
      
      //  approach 2
      ListNode* slow=head, *fast=head;
      
      while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
      }
      
      return slow;
    }
};
