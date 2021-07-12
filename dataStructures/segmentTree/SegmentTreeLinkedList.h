template <typename T>
class SegmentTree {
 public:
  size_t leftmost, rightmost;

  SegmentTree<T>* leftChild;
  SegmentTree<T>* rightChild;

  T(*compa)
  (T, T);

  T value;

  SegmentTree(const size_t startIdx, const size_t endIdx, T* arr, T (*fun)(T, T)) : leftmost(startIdx), rightmost(endIdx), compa(fun) {
    if (this->leftmost == this->rightmost) {  //  leaf
      this->value = arr[this->leftmost];      //  filling the segment tree from left

      this->leftChild = nullptr;
      this->rightChild = nullptr;
    } else {  //  have two children
      T mid = this->leftmost + (this->rightmost - this->leftmost) / 2;

      //  using postorder
      this->leftChild = new SegmentTree<T>(this->leftmost, mid, arr, fun);
      this->rightChild = new SegmentTree<T>(mid + 1, this->rightmost, arr, fun);

      this->recalculateVal();
    }
  }

  void recalculateVal() {
    this->value = this->compa(this->leftChild->value, this->rightChild->value);
  }

  T rangeQuery(const size_t l, const size_t r) {
    //  disjoint
    if (l > this->rightmost || r < this->leftmost) return 0;

    //  complete overlap
    if (l <= this->leftmost && r >= this->rightmost) return this->value;

    //  partial overlap
    return this->compa(this->leftChild->rangeQuery(l, r), this->rightChild->rangeQuery(l, r));
  }

  void pointUpdate(size_t idx, const T& val) {
    if (this->leftmost == this->rightmost) {
      this->value = val;
      return;
    } else if (idx <= this->leftChild->rightmost)
      this->leftChild->pointUpdate(idx, val);
    else
      this->rightChild->pointUpdate(idx, val);

    this->recalculateVal();
  }

  ~SegmentTree() {
    delete this->leftChild;
    this->leftChild = nullptr;

    delete this->rightChild;
    this->rightChild = nullptr;
  }
};
