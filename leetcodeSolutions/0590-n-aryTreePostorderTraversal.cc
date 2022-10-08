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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        auto dfs = [&](const auto &dfs, Node * const node){
            if(!node) {
                return ;
            }

            for(auto &child : node->children) {
                dfs(dfs, child);
            }

            ans.push_back(node->val);
        };
        dfs(dfs, root);

        return ans;
    }
};
