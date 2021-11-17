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
//         unordered_set<ListNode*> se;
//         se.insert(head);
        
//         while(head){
//             if(se.find(head->next)!=se.end()) return true;
            
//             se.insert(head->next);
//             head = head->next;
//         }
        
//         return false;
        
        //  0, 1 node, or 2nd node points to nullptr -> cycle is impossible
        if(head==nullptr || head->next==nullptr ||  head->next->next==nullptr) return false;
        
        ListNode* slow = head, *fast = head->next->next;
        
        while(slow!=fast){
            // if we get a nullptr, no cycle can exist
            if(slow->next == nullptr || fast->next == nullptr || fast->next->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //  loop breaks when slow == fast => there is a cycle
        return true;
    }
};
