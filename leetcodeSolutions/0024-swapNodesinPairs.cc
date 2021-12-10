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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==nullptr) return nullptr;
        
        if(head->next == nullptr) return head;
        
        //  first swaping the later ends
        if(head->next->next) head->next->next = swapPairs(head->next->next);
        
        ListNode* temp = head->next;
        
        head->next = head->next->next;
        temp->next = head;
        
        return temp;
    }
};
