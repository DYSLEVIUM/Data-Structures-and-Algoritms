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
    Solution(ListNode* head) {
        while(head) {
            m_nodes.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        int randd = rand() % m_nodes.size();
        return m_nodes[randd]->val;
    }
private:
    vector<ListNode *> m_nodes;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
