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
    ListNode* doubleIt(ListNode * const head) {
        auto reverse = [](ListNode * const head){
            ListNode * prev = nullptr, * curr = head, * next;
            while(curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        };

        ListNode * rev = reverse(head);
        
        int carry = 0;
        ListNode * curr = rev, * prev = nullptr;
        while(curr){
            curr->val = curr->val * 2 + carry;
            carry = curr->val > 9;
            curr->val %= 10;

            prev = curr;
            curr = curr->next;
        }

        if(carry) {
            prev->next = new ListNode(1);
        }

        return reverse(rev);
    }
};
