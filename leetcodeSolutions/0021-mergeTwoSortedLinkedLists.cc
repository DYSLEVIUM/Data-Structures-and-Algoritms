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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      //  Time: O(l1+l2)
      //  Space: O(l1+l2)
      
//       ListNode* head = new ListNode;
      
//       ListNode* te = head;
//       while(l1!=nullptr && l2!=nullptr){
//         if(l1->val<l2->val){
//           te->next = new ListNode(l1->val);
//           l1=l1->next;
//         }else{
//           te->next = new ListNode(l2->val);
//           l2=l2->next;
//         }
        
//         te=te->next;
//       }
      
//       while(l1!=nullptr){
//         te->next = new ListNode(l1->val);
//         l1=l1->next;
//         te=te->next;
//       }
      
//       while(l2!=nullptr){
//         te->next = new ListNode(l2->val);
//         l2=l2->next;
//         te=te->next;
//       }
      
//       return head->next;
      
      //  Time: O(l1+l2)
      //  Space: O(1)
      if(l1==nullptr) return l2;
      if(l2==nullptr) return l1;
            
      if(l1->val>l2->val) swap(l1, l2);
      
      ListNode* res = l1;
      
      while(l1!=nullptr && l2!=nullptr){
        ListNode* temp = nullptr;

        while(l1!=nullptr && l1->val<=l2->val){
          temp = l1;
          l1=l1->next;
        }
        
        temp->next = l2;
        swap(l1, l2);
      }
      
      return res;
    }
};
