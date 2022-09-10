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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      if(!head || !head->next || !head->next->next) {
        return {-1, -1};
      }
      
      int dist = 0;
      ListNode *prev = head, *node = head->next, *nex = node->next;
      
      vector<pair<ListNode *, int>> crit_points;
      while(nex) {
        if(node->val > prev->val && node->val > nex->val) {
          crit_points.push_back({node, dist});
        }
        
        if(node->val < prev->val && node->val < nex->val) {
          crit_points.push_back({node, dist});
        }
        
        prev = prev->next;
        node = node->next;
        nex = nex->next;
        
        ++dist;
      }
      
      if(crit_points.size() < 2) {
        return {-1, -1};
      }
      
      sort(crit_points.begin(), crit_points.end(), [](const auto &lhs, const auto &rhs){
        return lhs.second < rhs.second;
      });
      
      int minn = INT_MAX;
      for(int i = 1; i < crit_points.size(); ++i) {
        minn = min(minn, crit_points[i].second - crit_points[i - 1].second);
      }
      
      int maxx = crit_points.back().second - crit_points.front().second;
      
      return {minn, maxx};
    }
};
