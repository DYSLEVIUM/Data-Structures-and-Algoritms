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
    ListNode* sortList(ListNode* head) {
      if(!head  || !head->next) return head;
      
      ListNode* prev = nullptr, *tortoise = head, *hare = head;
      
      while(hare && hare->next){
        hare = hare->next->next;
        prev = tortoise;
        tortoise = tortoise->next;
      }
      
      prev->next = nullptr;
      
      ListNode* first_half = sortList(head);
      ListNode* second_half = sortList(tortoise);
      
      auto merge = [](ListNode* first, ListNode* second){
        if(!first) return second;
        if(!second) return first;
        
        ListNode *smaller = first, *larger = second;
        if(smaller->val > larger->val) swap(smaller, larger);
        
        ListNode* head = smaller;
        
        while(smaller && larger){
          ListNode* temp = smaller;
          while(smaller && smaller->val <= larger->val){
            temp = smaller;
            smaller = smaller->next;
          }
          
          temp->next = larger;
          swap(smaller, larger);
        }
        
        return head;
      };
      
      return merge(first_half, second_half);
    }
};
