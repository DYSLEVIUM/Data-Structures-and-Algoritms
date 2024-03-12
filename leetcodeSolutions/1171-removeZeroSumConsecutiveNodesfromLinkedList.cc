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

#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        int sum = 0;
        ListNode *node = dummy;
        unordered_map<int, ListNode*> mp;
        while(node) {
            sum += node->val;
            mp[sum] = node; // overwriting, to get the rightmost
            node = node->next;
        }

        sum = 0;
        node = dummy;
        while(node) {
            sum += node->val;
            node->next = mp[sum]->next;

            // cleaning memory
            {
                ListNode * temp = node->next;
                ListNode * target = mp[sum]->next;
                while(temp != target) {
                    ListNode * next = temp->next;
    
                    delete temp;
                    temp = next;
                }
            }
            
            node = node->next;
        }

        head = dummy->next;

        // delete dummy;
        // dummy = nullptr;

        return dummy->next;
    }
};

class Solution1 {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        int sum = 0;
        ListNode *node = dummy;
        unordered_map<int, ListNode*> mp;
        while(node) {
            sum += node->val;
            if(mp.count(sum)) {
                node = mp[sum]->next;

                int p = sum + node->val;
                while (p != sum) {
                    mp.erase(p);
                    node = node->next;
                    p += node->val;
                }
                mp[sum]->next = node->next;
            } else {
                mp[sum] = node;
            }
            node = node->next;
        }

        return dummy->next;
    }
};
