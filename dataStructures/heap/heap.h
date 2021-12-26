//  it must be a full binary tree, i.e., left child should be filled before the right child
template <typename T, typename __comp = std::less<T>>
class Heap {
 private:
  uint64_t _size{};
  vector<T> _data{-1};
  __comp cmp = __comp{};

  uint64_t parent(const uint64_t& i) const { return i >> 1; };
  uint64_t left_child(const uint64_t& i) const { return i << 1; };
  uint64_t right_child(const uint64_t& i) const { return (i << 1) + 1; };
  bool node_exists(const uint64_t& i) const { return i < this->_size; };

  //  we always heapify the subtrees, this is different from the create_heap where on insertion, we used to heap up (for n nodes, we have to bubble up with height of log n, so time complexity is O(n log n)) and on deletion we used to heap down
  void heapify(const uint16_t& idx) {  //  heap down implementation
    if (idx >= this->_size) return;

    heapify(left_child(idx));
    heapify(right_child(idx));

    if (node_exists(left_child(idx)) && cmp(this->_data[idx], this->_data[left_child(idx)])) {
      swap(this->_data[left_child(idx)], this->_data[idx]);
      heapify(left_child(idx));
    }

    if (node_exists(right_child(idx)) && cmp(this->_data[idx], this->_data[right_child(idx)])) {
      swap(this->_data[right_child(idx)], this->_data[idx]);
      heapify(right_child(idx));
    }
  };

 public:
  Heap() : _size(1){};

  bool is_empty() const { return this->_size == 1; };

  uint64_t size() const { return this->_size - 1; };

  T top() const { return this->_data[1]; };

  void push(const T& da) {
    //  making space to insert
    if (this->_size + 1 >= this->_data.size()) this->_data.push_back(-1);

    this->_data[this->_size++] = da;

    this->heapify(1);
  };

  void pop() {
    if (this->_size == 1) return;

    //  putting the last element at top
    swap(this->_data[1], this->_data[--this->_size]);

    this->_data.pop_back();  //  deleting the node

    this->heapify(1);
  };
};
