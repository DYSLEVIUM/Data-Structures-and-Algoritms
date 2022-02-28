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
    bool isPalindrome(ListNode* head) {
      ListNode *prev = nullptr;
      
      //  we go on reversing the links of the first half so that we can iterate through it
      ListNode *fast = head, *slow = head;
      while(fast && fast->next){
        fast = fast->next->next;
        
        ListNode* next_node = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next_node;
      }

      ListNode* next_node = slow; //  this is middle node right now

      //  if fast is nullptr, it means there are even number of nodes
      if(fast){
        //  here slow would have been at the middle node, which is irrelevant in palindrome of odd length
        slow = slow->next;
      }
      
      
      bool is_palindrome = true;
      //  we iterate full and not return the asnwer as is because we want to make the linked list the same as before
      while(slow){
        if(slow->val != prev->val) is_palindrome = false;
        
        //  reverse the links to original state
        ListNode* te = prev->next;
        prev->next = next_node;
        next_node = prev;
        prev = te;
        
        slow = slow->next;
      }
      
      return is_palindrome;
    }
};
