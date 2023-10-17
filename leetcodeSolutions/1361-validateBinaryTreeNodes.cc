class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        auto find_root = [&](){
            unordered_set<int> children;
            children.insert(leftChild.begin(), leftChild.end());
            children.insert(rightChild.begin(), rightChild.end());

            for(int i = 0; i < n; ++i) {
                if(children.find(i) == children.end()) {
                    return i;
                }
            }

            return -1;
        };

        unordered_set<int> seen;
        auto check_bin = [&](const auto& check_bin, const int & node){
            if(node == -1) { // valid tree
                return true;
            }

            if(seen.find(node) != seen.end()) { // cycle detected
                return false;
            }
            seen.insert(node);

            return check_bin(check_bin, leftChild[node]) && check_bin(check_bin, rightChild[node]);
        };

        int root = find_root();
        if(root == -1) {
            return false;
        }

        return check_bin(check_bin, root) && seen.size() == n; // checking seen size for disconnected graph
    }
};
