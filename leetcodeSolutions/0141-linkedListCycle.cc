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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> se;
        se.insert(head);
        
        while(head){
            if(se.find(head->next)!=se.end()) return true;
            
            se.insert(head->next);
            head = head->next;
        }
        
        return false;
    }
};
