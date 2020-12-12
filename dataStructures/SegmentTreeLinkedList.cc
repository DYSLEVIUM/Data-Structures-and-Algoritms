template <typename T>
class SegmentTree {
   public:
    T leftmost, rightmost;
    SegmentTree<T>* leftChild;
    SegmentTree<T>* rightChild;

    //  range sum queries
    T sum;

    SegmentTree(T lm, T rm, T* arr) : leftmost(lm), rightmost(rm) {
        if (leftmost == rightmost) {
            //  leaf
            this->sum = arr[leftmost];
        } else {
            //  have two children
            T mid = leftmost + (rightmost - leftmost) / 2;

            //  using postorder to calculate sum again
            this->leftChild = new SegmentTree<T>(leftmost, mid, arr);
            this->rightChild = new SegmentTree<T>(mid + 1, rightmost, arr);

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

    ~SegmentTree() {
    }
};
