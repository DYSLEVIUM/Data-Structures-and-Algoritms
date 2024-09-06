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
    ListNode* modifiedList(const vector<int> & nums, const ListNode * const head) {
        const unordered_set<int> nums_se(nums.begin(), nums.end());

        const ListNode dummy(0, const_cast<ListNode *>(head));

        ListNode * prev = const_cast<ListNode *>(&dummy);
        const ListNode * curr = const_cast<ListNode *>(head);
        while(curr) {
            const ListNode * next = curr->next;

            if(nums_se.count(curr->val)) {
                prev->next = const_cast<ListNode *>(next);

                delete curr;
                curr = nullptr;
            } else {
                prev = const_cast<ListNode *>(curr);
            }

            curr = next;
        }

        return dummy.next;
    }
};
