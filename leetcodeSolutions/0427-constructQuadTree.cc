/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size() : 0;
        if(!rows) return nullptr;

        // this doesn't seem efficient 🥲
        auto check_same = [&grid](const int &r1, const int &c1, const int &r2, const int &c2){
            for(int r = r1; r <= r2; ++r) {
                for(int c = c1; c <= c2; ++c) {
                    if(grid[r][c] != grid[r1][c1]) return false;
                }
            }
            return true;
        };

        auto make_quad = [&](const auto& make_quad, const int &r1, const int &c1, const int &r2, const int &c2) -> Node * {
            Node *node = new Node(grid[r1][c1], true);
            if(!check_same(r1, c1, r2, c2)) {
                node->isLeaf = false;
                int dr = (r2 - r1) >> 1, dc = (c2 - c1) >> 1;
                node->topLeft = make_quad(make_quad, r1, c1, r1 + dr, c1 + dc);
                node->topRight = make_quad(make_quad, r1, c1 + dc + 1, r1 + dr, c2);
                node->bottomLeft = make_quad(make_quad, r1 + dr + 1, c1, r2, c1 + dc);
                node->bottomRight = make_quad(make_quad, r1 + dr + 1, c1 + dc + 1, r2, c2);
            }
            return node;
        };

        return make_quad(make_quad, 0, 0, rows - 1, cols - 1);
    }
};
