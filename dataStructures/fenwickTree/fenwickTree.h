//  use primarily for cumulative frequency tables
template <typename T>
class FenwickTree {
  // one based indexing
 private:
  size_t _size;
  vector<T> _data;

  T(*comp)
  (const T&, const T&);

 public:
  FenwickTree(const vector<T>& arr, T (*fun)(const T&, const T&)) : _size(arr.size() + 1), comp(fun) {
    this->_data.assign(this->_size + 1, 0);

    Fo(i, 1, this->_size) this->update(i, arr[i - 1]);
  }

  T query(size_t x) {  // query for first x elements in the array, x is taken as 0 and is processed
    ++x;               // 0 to 1 based indexing
    T val = 0;

    while (x > 0) {
      val = comp(this->_data[x], val);
      x -= (x & -x);  // getting val from the other nodes
    }

    return val;
  }

  void update(size_t x, const T& delta) {
    ++x;  // 0 to 1 based indexing
    while (x < this->_size) {
      this->_data[x] = comp(this->_data[x], delta);  // add the delta to all the nodes, updating the subtrees
      x += (x & -x);                                 // (x&-x) isolates the last set bit
    }
  }
};
