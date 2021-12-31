//  it must be a complete binary tree, i.e., left child should be filled before the right child
template <typename T, typename __comp = std::less<T>>
class Heap {
 private:
  uint64_t _size;
  vector<T> _data;
  __comp cmp = __comp{};

  uint64_t parent(const uint64_t& i) const { return i >> 1; };
  uint64_t left_child(const uint64_t& i) const { return (i << 1) + 1; };
  uint64_t right_child(const uint64_t& i) const { return (i << 1) + 2; };
  bool node_exists(const uint64_t& i) const { return i < this->_size; };

  //  we always heapify the subtrees, this is different from the create_heap where on insertion, we used to heap up (for n nodes, we have to bubble up with height of log n, so time complexity is O(n log n)) and on deletion we used to heap down
  void heapify(const uint16_t& idx) {  //  heap down implementation
    if (idx >= this->_size) return;

    uint64_t left_idx = left_child(idx);
    uint64_t right_idx = right_child(idx);

    //  first on the leaf nodes
    heapify(left_idx);
    heapify(right_idx);

    if (node_exists(left_idx) && cmp(this->_data[idx], this->_data[left_idx])) {
      swap(this->_data[left_idx], this->_data[idx]);
      heapify(left_idx);
    }

    if (node_exists(right_idx) && cmp(this->_data[idx], this->_data[right_idx])) {
      swap(this->_data[right_idx], this->_data[idx]);
      heapify(right_idx);
    }
  };

 public:
  Heap() : _size(0){};

  bool is_empty() const { return this->_size == 0; };

  uint64_t size() const { return this->_size; };

  T top() const { return this->_data[0]; };

  void push(const T& da) {
    //  making space to insert
    if (this->_size + 1 >= this->_data.size()) this->_data.push_back(-1);

    this->_data[this->_size++] = da;

    this->heapify(0);
  };

  void pop() {
    if (!this->_size) return;

    //  putting the last element at top
    swap(this->_data[0], this->_data[--this->_size]);

    this->_data.pop_back();  //  deleting the node

    this->heapify(0);
  };
};
