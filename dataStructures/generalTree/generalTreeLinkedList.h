template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode*> children;

    TreeNode(T da) : data(da) {}

    T getData() {
        return this->data;
    }
};

template <typename T>
void levelOrderTraversal(TreeNode<T>* root) {
    if (root == nullptr) return;

    queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        while (n--) {
            //  dequeue an item from queue and print it
            TreeNode<T>* p = q.front();
            q.pop();
            cout << p->getData() << ' ';

            //  enqueue all children of the dequeued item
            for (int i = 0; i < p->children.size(); ++i) {
                q.push(p->children[i]);
            }
        }
        cout << '\n';
    }
}
