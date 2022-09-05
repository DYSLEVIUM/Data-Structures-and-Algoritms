/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      vector<vector<int>> ans;
      
      if(!root) {
        return ans;
      }
      
      queue<Node *> qu;
      qu.push(root);
      while(!qu.empty()) {
        int sz = qu.size();
        vector<int> curr_ans;
        while(sz--) {
          Node *fr = qu.front();
          qu.pop();
          
          for(auto &child : fr->children) {
            qu.push(child);
          }
          
          curr_ans.push_back(fr->val);
        }
        
        ans.push_back(curr_ans);
      }
      
      return ans;
    }
};
