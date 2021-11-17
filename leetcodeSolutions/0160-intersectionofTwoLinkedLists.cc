/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> se;
        
        while(headA){
            se.insert(headA);
            headA = headA->next;
        }
        
        while(headB){
            if(se.find(headB)!=se.end()) return headB;
            headB = headB->next;
        }
        
        return nullptr;
    }
};
