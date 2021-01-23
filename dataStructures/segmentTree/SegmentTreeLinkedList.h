template <typename T>
class SegmentTree {
   public:
    T leftmost, rightmost;
    SegmentTree<T>* leftChild;
    SegmentTree<T>* rightChild;

    //  range sum queries
    T sum;

    SegmentTree(T stIdx, T endIdx, T* arr) : leftmost(stIdx), rightmost(endIdx) {
        if (this->leftmost == this->rightmost) {
            //  leaf
            this->sum = arr[this->leftmost];  //  filling the segment tree from left

            this->leftChild = nullptr;
            this->rightChild = nullptr;
        } else {
            //  have two children
            T mid = this->leftmost + (this->rightmost - this->leftmost) / 2;

            //  using postorder to calculate sum again
            this->leftChild = new SegmentTree<T>(this->leftmost, mid, arr);
            this->rightChild = new SegmentTree<T>(mid + 1, this->rightmost, arr);

            this->sum = this->leftChild->sum + this->rightChild->sum;
        }
    }

    void update(T index, T val) {
        if (this->leftmost == this->rightmost) {
            //  leaf
            sum = val;
        } else {
            // have two children
            if (index <= this->leftChild->rightmost) {
                this->leftChild->update(index, val);
            } else {
                this->rightChild->update(index, val);
            }

            // recalculating sum after update
            this->sum = this->leftChild->sum + this->rightChild->sum;
        }
    }

    T rangeSum(T l, T r) {
        //  entirely disjoint
        if (l > rightmost || r < leftmost) return 0;

        //  complete overlap
        if (l <= leftmost && r >= rightmost) return sum;

        //  partial overlap
        return this->leftChild->rangeSum(l, r) + this->rightChild->rangeSum(l, r);
    }

    //  can't find the bug 😅
    // ~SegmentTree() {
    //     stack<SegmentTree<T>*> st;

    //     if (this->leftChild != nullptr) st.push(this->leftChild);
    //     if (this->rightChild != nullptr) st.push(this->rightChild);

    //     delete this;

    //     while (!st.empty()) {
    //         SegmentTree<T>* topNode = st.top();
    //         st.pop();

    //         if (topNode->leftChild != nullptr) st.push(topNode->leftChild);

    //         if (topNode->rightChild != nullptr) st.push(topNode->rightChild);

    //         delete topNode;
    //     }
    // }
};
