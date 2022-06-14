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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        
        auto cmp = [](ListNode * const l1, ListNode * const l2){
            return l1->val > l2->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> min_heap(cmp); 
        
        for(ListNode *list: lists) {
            if(list) min_heap.push(list);
        }
        
        if(min_heap.empty()) return nullptr;
        
        ListNode *head = min_heap.top();
        min_heap.pop();
        ListNode *node = head;
        ListNode *prev = nullptr;
        while(!min_heap.empty()) {
            ListNode *tp = min_heap.top();
            min_heap.pop();
            while(node && node->val <= tp->val){
                prev = node;
                node = node->next;
            }
            
            if(node) min_heap.push(node);
            
            node = prev;
            node->next = tp;
        }
        
        return head;
    }
};
