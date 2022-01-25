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
    int getDecimalValue(ListNode* head) {
      int lenght = 0;
      ListNode* temp_head = head;
      
      while(temp_head){
        temp_head = temp_head->next;
        ++lenght;
      }
      
      auto dfs = [](const auto& dfs, const ListNode* const node, const int len){
        if(!node) return 0;
        
        return (1<<(len-1))*node->val + dfs(dfs, node->next, len-1);
      };
      
      return dfs(dfs, head, lenght);
    }
};
