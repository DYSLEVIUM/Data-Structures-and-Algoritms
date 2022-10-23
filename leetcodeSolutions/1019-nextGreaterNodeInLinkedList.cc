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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> ans;
        auto dfs = [&](const auto & dfs, ListNode * const & node){
            if(!node) return ;

            dfs(dfs, node->next);
        
            while(!st.empty() && node->val >= st.top()) st.pop();
            
            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.top());

            st.push(node->val);
        };
        dfs(dfs, head);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
