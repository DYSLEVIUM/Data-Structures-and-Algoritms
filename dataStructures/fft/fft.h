template <typename T>
class FFT {
 private:
  size_t get_length(const size_t& s) const { return s > 1 ? 32 - __builtin_clz(s - 1) : 0; }

  void fft(vector<complex<double>>& a) {
    size_t n = a.size();

    //  bit-reversal
    for (size_t i = 1, j = 0; i < n; ++i) {
      ll bit = n >> 1;

      while (j & bit) {
        j ^= bit;
        bit >>= 1;
      }
      j ^= bit;

      if (i < j) swap(a[i], a[j]);
    }

    //  pre-computing roots
    vector<complex<double>> roots(n);
    for (size_t i = 0; i < n; ++i) roots[i] = complex<double>(cos(2 * PI * i / n), sin(2 * PI * i / n));

    for (size_t len = 2; len <= n; len <<= 1) {
      size_t te = len / 2;
      for (size_t i = 0; i < n; i += len) {
        for (size_t j = 0; j < te; ++j) {
          complex<double> z = a[te + i + j] * roots[n / len * j];
          a[te + i + j] = a[i + j] - z;
          a[i + j] += z;
        }
      }
    }
  }

  void fft_inverse(vector<complex<double>>& a) {
    size_t n = a.size();

    this->fft(a);

    for (auto& x : a) x /= n;

    reverse(a.begin() + 1, a.end());
  }

 public:
  //  convolution a * b
  vector<complex<double>> conv(vector<complex<double>> a, vector<complex<double>> b) {
    size_t s = a.size() + b.size() - 1;
    if (s <= 0) return {};

    size_t len = this->get_length(s);
    size_t n = 1 << len;

    a.resize(n);
    this->fft(a);

    b.resize(n);
    this->fft(b);

    for (size_t i = 0; i < n; ++i) a[i] *= b[i];

    this->fft_inverse(a);

    a.resize(s);
    return a;
  }

  vector<T> conv(const vector<T>& a, const vector<T>& b) {
    vector<complex<double>> X = conv(vector<complex<double>>(a.begin(), a.end()), vector<complex<double>>(b.begin(), b.end()));

    size_t n = X.size();

    vl x(n);
    for (size_t i = 0; i < n; ++i) x[i] = round(X[i].real());

    return x;
  }
};
