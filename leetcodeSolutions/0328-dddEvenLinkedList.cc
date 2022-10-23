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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;

        ListNode * odd_h = head, * even_h = head->next;
        ListNode * odd = odd_h, * even = even_h;
        while(even && even->next) {
            ListNode * temp = even->next;
            
            odd->next = temp;
            even->next = temp->next;

            odd = odd->next;
            even = even->next;
        }
        
        odd->next = even_h;

        return odd_h;
    }
};
