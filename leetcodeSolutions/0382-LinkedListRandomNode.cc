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
    ListNode *head;
public:
    Solution(ListNode* head): head(head) {}
    
    // reservoir sampling
    /*
        1. The key point is before we process the N-th element, the probability of each previous N-1 element is equal to each other. This is very important.
        2. So after processing N-th element, the probability of each previous N-1 element is still equal to each other.
        3. At this time, the probability of N-th element is 1/N with no doubt, and the rest (1 - 1 / N) = (N - 1) / N will be shared equally by previous N - 1 elements, that is (1 - 1 / N) / (N - 1) = K(N - 1) / N / (N - 1) = 1 / N
        4. Cost O(N) for getRandom every time
        5. You may wonder since the time complexity is still O(N), why do we have to spend so much; that is because in the case of streaming data, we cannot traverse all the data to obtain the length, and then traverse the data again.
    */
    int getRandom() {
        ListNode * node = head;

        ListNode * random_node = nullptr;
        int i = 0;
        while(node) {
            ++i;
            
            int prob = rand() % i;
            if(!prob) {
                random_node = node;
            }

            node = node->next;
        }

        return random_node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
