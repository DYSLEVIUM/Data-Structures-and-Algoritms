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
//         unordered_set<ListNode*> se;
        
//         while(headA){
//             se.insert(headA);
//             headA = headA->next;
//         }
        
//         while(headB){
//             if(se.find(headB)!=se.end()) return headB;
//             headB = headB->next;
//         }
        
//         return nullptr;
        
        auto getLength = [](ListNode* head){
            int len = 0;
            while(head->next){
                head = head->next;
                ++len;
            }
            
            return len;
        };

        
        // making both the lists equidistant from the right end
        int lenA = getLength(headA), lenB = getLength(headB);
        
        while(lenA>lenB){
            headA = headA->next;
            --lenA;
        }
        
        while(lenA<lenB){
            headB = headB->next;
            --lenB;
        }
        
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};
