template <typename T>
class NTT {
 private:
  T get_length(const size_t& s) const { return s > 1 ? 32 - __builtin_clz(s - 1) : 0; }

  void ntt(vector<T>& a) {
    T n = a.size();

    //  bit-reversal
    for (size_t i = 1, j = 0; i < n; ++i) {
      T bit = n >> 1;

      while (j & bit) {
        j ^= bit;
        bit >>= 1;
      }
      j ^= bit;

      if (i < j) swap(a[i], a[j]);
    }

    //  pre-computing roots
    vector<T> roots(n);
    roots[0] = 1, roots[1] = bin_pow_m<T>(this->_root, (this->_mod - 1) / n, this->_mod);
    for (size_t i = 2; i < n; ++i) roots[i] = mod_mul(roots[i - 1], roots[1], this->_mod);

    for (size_t len = 2; len <= n; len <<= 1) {
      T te = len / 2;
      for (size_t i = 0; i < n; i += len) {
        for (size_t j = 0; j < te; ++j) {
          T z = mod_mul(a[te + i + j], roots[n / len * j], this->_mod);
          a[te + i + j] = mod_sub(a[i + j], z, this->_mod);
          a[i + j] = mod_add(a[i + j], z, this->_mod);
        }
      }
    }
  }

  void ntt_inverse(vector<T>& a) {
    size_t n = a.size();

    T inv = mod_inverse<T>(n, this->_mod);
    this->ntt(a);

    for (T& x : a) x = mod_mul<T>(x, inv, this->_mod);

    reverse(a.begin() + 1, a.end());
  }

 public:
  T _mod, _root;

  NTT(const ll& mod, const ll& root) : _mod(mod), _root(root) {}

  //  convolution a * b
  vector<T> conv(vector<T> a, vector<T> b) {
    size_t s = a.size() + b.size() - 1;
    if (s <= 0) return {};

    size_t len = this->get_length(s);
    size_t n = 1 << len;

    a.resize(n);
    this->ntt(a);

    b.resize(n);
    this->ntt(b);

    for (size_t i = 0; i < n; ++i) a[i] = mod_mul(a[i], b[i], this->_mod);

    this->ntt_inverse(a);

    a.resize(s);
    return a;
  }
};
