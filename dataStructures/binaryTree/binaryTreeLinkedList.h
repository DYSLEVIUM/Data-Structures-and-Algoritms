template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T da) : data(da), left(nullptr), right(nullptr) {
    }

    T getData() {
        return this->data;
    }
};

template <typename T>
void levelOrderTraversal(BinaryTreeNode<T>* root) {
    if (root == nullptr) return;

    queue<BinaryTreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        while (n--) {
            //  dequeue an item from queue and print it
            BinaryTreeNode<T>* p = q.front();
            q.pop();
            cout << p->getData() << ' ';

            //  enqueue all children of the dequeued item
            if (p->left != nullptr) q.push(p->left);
            if (p->right != nullptr) q.push(p->right);
        }
        cout << '\n';
    }
}
