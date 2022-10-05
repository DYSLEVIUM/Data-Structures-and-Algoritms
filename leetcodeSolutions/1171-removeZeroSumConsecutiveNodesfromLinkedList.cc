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
            node = node->next;
        }

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
