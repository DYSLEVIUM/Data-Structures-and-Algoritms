template <typename T>
class Sparse_Table {
 private:
  vector<vector<T>> _table;
  vector<T> log_values;
  size_t _size;
  T max_log;
  T _identity;  //  identity element, e: e * a = a * e = a
  T(*_fun)
  (const T&, const T&);
  bool _is_idempotent; //  idempotent property: a * a = a

  void build() {
    //  we take two numbers from previous column, i and i+(2^(j-1))
    for (size_t j = 1; j <= this->max_log; ++j) {
      for (size_t i = 0; i + (1 << j) <= this->_size; ++i) this->_table[i][j] = this->_fun(this->_table[i][j - 1], this->_table[i + (1 << (j - 1))][j - 1]);
    }
  }

 public:
  Sparse_Table(const vector<T>& data, T (*fun)(const T&, const T&), const T& identity, const bool& is_idempotent) : _size(data.size()), _fun(fun), _identity(identity), _is_idempotent(is_idempotent) {
    this->_table.resize(this->_size);

    //  storing the computed log values
    this->log_values.resize(this->_size + 1);
    this->max_log = log2(this->_size);
    this->log_values[1] = 0;
    for (size_t i = 2; i <= max_log; ++i) log_values[i] = log_values[i >> 1] + 1;

    //  resizing the table
    for (size_t i = 0; i < this->_size; ++i) {
      this->_table[i].resize(this->max_log + 1);
      fill(this->_table[i].begin(), this->_table[i].end(), this->_identity);
    }

    //  filling the first column
    for (size_t i = 0; i < this->_size; ++i) this->_table[i][0] = data[i];

    this->build();
  }

  T query(size_t le, size_t ri) {
    //  query in O(1) for idempotent function
    if (this->_is_idempotent) {
      size_t j = this->log_values[ri - le + 1];
      return this->_fun(this->_table[le][j], this->_table[ri - (1 << j) + 1][j]);
    }

    T ans = this->_identity;
    for (int j = this->log_values[ri - le + 1]; j >= 0; --j) {
      if ((1 << j) > ri - le + 1) {
        continue;
      }
     
      ans = this->_fun(ans, this->_table[le][j]);
      le += 1 << j;
    }

    return ans;
  }
};

inline void solve() {
  vl a(25);
  iota(all(a), 1);

  auto sum = [](const ll& x, const ll& y) { return x + y; };

  Sparse_Table<ll> sp(a, sum, 0, false);

  cout << sp.query(2, 6) << '\n';
}
