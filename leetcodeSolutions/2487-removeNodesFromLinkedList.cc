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
    ListNode* removeNodes(ListNode* head) {
        if(!head) {
            return nullptr;
        }

        head->next = removeNodes(head->next);
        if(head->next && head->next->val > head->val) {
            return head->next;
        }

        return head;
    }
};

class Solution1 {
public:
    ListNode* removeNodes(ListNode* head) {
        constinit static const int INF = 0x3f3f3f;

        auto pre_order = [](const auto & pre_order, ListNode * node, int & maxx) -> ListNode * {
            if(!node) {
                return nullptr;
            }

            node->next = pre_order(pre_order, node->next, maxx);
            if(maxx > node->val) {
                ListNode * temp = node;
                node = node->next;

                delete temp;
                temp = nullptr;
            } else {
                maxx = node->val;
            }

            return node;
        };

        int maxx = -INF;
        return pre_order(pre_order, head, maxx);
    }
};
