/*  it must be a complete binary tree, i.e., left child should be filled before
 * the right child */
template <typename T, typename __comp = std::less<T>> class Heap {
public:
  Heap() : m_size(0){};

  bool empty() const { return m_size == 0; };
  int size() const { return m_size; };
  T top() const { return m_data[0]; };

  void push(const T &curr_data) {
    //  making space to insert
    if (m_size + 1 >= m_data.size())
      m_data.push_back(-1);

    m_data[m_size++] = curr_data;

    heapify(0);
  };

  void pop() {
    if (!m_size) {
      return;
    }
    //  putting the last element at top
    std::swap(m_data[0], m_data[--m_size]);

    m_data.pop_back(); //  deleting the node

    heapify(0);
  };

private:
  int m_size;
  std::vector<T> m_data;
  __comp cmp = __comp{};

  int parent(const int &i) const { return i >> 1; };
  int left_child(const int &i) const { return (i << 1) + 1; };
  int right_child(const int &i) const { return (i << 1) + 2; };
  bool node_exists(const int &i) const { return i < m_size; };

  //  we always heapify the subtrees, this is different from the create_heap
  //  where on insertion, we used to heap up (for n nodes, we have to bubble up
  //  with height of log n, so time complexity is O(n log n)) and on deletion we
  //  used to heap down
  void heapify(const uint16_t &idx) { //  heap down implementation
    if (idx >= m_size)
      return;

    int left_idx = left_child(idx);
    int right_idx = right_child(idx);

    //  first on the leaf nodes
    heapify(left_idx);
    heapify(right_idx);

    if (node_exists(left_idx) && cmp(m_data[idx], m_data[left_idx])) {
      std::swap(m_data[left_idx], m_data[idx]);
      heapify(left_idx);
    }

    if (node_exists(right_idx) && cmp(m_data[idx], m_data[right_idx])) {
      std::swap(m_data[right_idx], m_data[idx]);
      heapify(right_idx);
    }
  };
};
