/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node *, Node *> mp;
        auto dfs = [&mp](const auto &dfs, Node * const &node) -> Node * {
            // this will only run when the root is nullptr
            if(!node) {
                return nullptr;
            }
            
            if(!mp.count(node)) {
                Node *clone_node = new Node(node->val);
                mp[node] = clone_node;
                
                for(auto &neigh : node->neighbors) {
                    clone_node->neighbors.push_back(dfs(dfs, neigh));
                }
            }
            
            return mp[node];
        };
        
        
        return dfs(dfs, node);
    }
};
