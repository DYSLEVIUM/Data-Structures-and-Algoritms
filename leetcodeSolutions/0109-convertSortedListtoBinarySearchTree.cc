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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        
        auto get_mid = [](ListNode *le, ListNode *ri) {
            ListNode *slow = le;
            ListNode *fast = le;
            
            ListNode *prev = le;
            while(fast != ri && fast->next != ri) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            
            //  slow is the middle node
            return slow;
        };
        
        auto make_tree = [&](const auto &make_tree, ListNode *le, ListNode *ri) -> TreeNode *{
            //  extreme left side edge case
            if(le == ri) {
                return nullptr;
            }
            
            //  extreme right side edge case
            if(le->next == ri) {
                return new TreeNode(le->val);                                
            }
            
            auto mid = get_mid(le, ri);
        
            TreeNode *node = new TreeNode(mid->val);
            node->left = make_tree(make_tree, le, mid);
            node->right = make_tree(make_tree, mid->next, ri);
            
            return node;
        };
        
        return make_tree(make_tree, head, nullptr);
    }
};
