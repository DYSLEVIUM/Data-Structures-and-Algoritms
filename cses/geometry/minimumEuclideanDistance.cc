// headers
#ifdef DYSLEVIUM
#include "dyslevium.h"
#else
//  optimizations done at compile time
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

// clang-format off
//  custom functions
std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());  // generator for shuffle and other generator which require random numbers
// modified custom hash to used with templates from https://codeforces.com/blog/entry/62393  
template<typename T>
class custom_hash {
 public:
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
 
  size_t operator()(T x) const {
    static const uint64_t FIXED_RANDOM = RNG();
    return splitmix64(std::hash<T>()(x) + FIXED_RANDOM);
  }
};
 
//  aliases
using ll = long long;
using ld = long double;
using pl = std::pair<ll, ll>;
using vl = std::vector<ll>;
using vvl = std::vector<vl>;
using vpl = std::vector<pl>;
template <typename key, typename value> using pbds_map = __gnu_pbds::gp_hash_table<key, value, custom_hash<key>>; //  4x - 10x faster than stl unordered_map
template <typename T> using pbds_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;  // find_by_order, order_of_key
 
//  constants
constexpr ll INF(2e18);
constexpr ld EPS(1e-9);
constexpr ll MOD(1e9 + 7);  //  or (119 << 23) + 1; primitive_root = 3; // = 998244353
constexpr ld PI(3.14159265358979323846);
 
//  macros
#define pb push_back
#define F first
#define S second
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
 
// template functions
template <typename T> inline T mod_add(const T& a, const T&  b, const T& mod) { return a + b > mod ? a + b - mod : (a + b); }
template <typename T> inline T mod_sub(const T& a, const T&  b, const T& mod) { return a - b < 0 ? a - b + mod : (a - b); }
template <typename T> inline T mod_mul(const T& a, const T&  b, const T& mod) { return ((((a % mod) * (b % mod)) % mod) + mod) % mod; };
template <typename T> inline T bin_pow(T x, T n) {T res = 1; while (n) { if (n & 1) res *= x; x *= x; n >>= 1; } return res; }
template <typename T> inline T bin_pow_m(T x, T n, const T& mod) {T res = 1; while (n) { if (n & 1) res = mod_mul(res, x, mod); x = mod_mul(x, x, mod); n >>= 1; } return res % mod; }
template <typename T> inline T mod_inverse(const T& a, const T& mod) { return bin_pow_m(a, mod - 2, mod); }
template <typename T> inline T mod_div(const T& a, const T& b, const T& mod) { return mod_mul(a, mod_inverse(b, mod), mod); }
 
//  operator overloading
template<typename T> std::istream& operator>>(std::istream &is, std::vector<T> &v){ for (auto &it : v) is >> it; return is; }
template<typename T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &v) { for (auto &it : v) os << it << ' '; return os; }
 
// debuging
#ifdef DYSLEVIUM
  #define deb(x) std::cerr << #x << " = " << x << '\n'
#else
  #define deb(x)
#endif
 
inline void solve();
 
inline void setup(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}
 
int main(int argc, char* argv[]) {
  setup(); 
 
  auto startTime = std::chrono::high_resolution_clock::now();
 
  ll t = 1;
  // std::cin >> t;
 
  while (t--) solve();
 
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
 
  #ifdef DYSLEVIUM
    std::cerr << "Time: " << duration.count();
  #endif
 
  return 0;
}
 
using namespace std;

// clang-format on
template <typename T>
class Point {
 public:
  T x, y;
  friend istream& operator>>(istream& is, Point<T>& p) {
    is >> p.x >> p.y;
    return is;
  }

  friend ostream& operator<<(ostream& os, const Point<T>& p) {
    os << p.x << ' ' << p.y;
    return os;
  }
};

inline void solve() {
  ll n;
  cin >> n;

  vector<Point<ll>> points(n);
  vl sorted_x, sorted_y;
  fo(i, n) {
    cin >> points[i];
    sorted_x.push_back(i);
    sorted_y.push_back(i);
  }

  sort(all(sorted_x), [&points](const ll& a, const ll& b) {
    return make_pair(points[a].x, points[a].y) <
           make_pair(points[b].x, points[b].y);
  });

  sort(all(sorted_y), [&points](const ll& a, const ll& b) {
    return make_pair(points[a].y, points[a].x) <
           make_pair(points[b].y, points[b].x);
  });

  auto euclid_dist = [](const Point<ll>& a, const Point<ll>& b) {
    return bin_pow(a.x - b.x, 2LL) + bin_pow(a.y - b.y, 2LL);
  };

  auto square = [](const ll& a) { return a * a; };

  //  divide and conquer
  auto get_ans = [&points, &euclid_dist, &square](const auto& get_ans,
                                                  const vl& sorted_x,
                                                  const vl& sorted_y) -> ll {
    //  base cases
    ll n = sorted_x.size();
    if (n == 2) return euclid_dist(points[sorted_x[0]], points[sorted_x[1]]);
    if (n == 3)
      return min({euclid_dist(points[sorted_x[0]], points[sorted_x[1]]),
                  euclid_dist(points[sorted_x[1]], points[sorted_x[2]]),
                  euclid_dist(points[sorted_x[0]], points[sorted_x[2]])});

    //  divide
    vl left_sorted_x(sorted_x.begin(), sorted_x.begin() + n / 2),
        right_sorted_x(sorted_x.begin() + n / 2, sorted_x.end());
    vl left_sorted_y, right_sorted_y;

    for (auto& id : sorted_y) {
      if (binary_search(sorted_x.begin(), sorted_x.begin() + n / 2, id))
        left_sorted_y.pb(id);
      else
        right_sorted_y.pb(id);
    }

    ll dist_l = get_ans(get_ans, left_sorted_x, left_sorted_y);
    ll dist_r = get_ans(get_ans, right_sorted_x, right_sorted_y);
    ll dist = min(dist_l, dist_r);

    ll mid_x = points[sorted_x[n / 2]].x;

    //  merge
    vl stripe_points;
    for (auto& id : sorted_y) {
      if (square(points[id].x - mid_x) < dist) stripe_points.push_back(id);
    }

    fo(i, (ll)stripe_points.size()) {
      for (ll j = i + 1; j < (ll)stripe_points.size() &&
                         square(points[stripe_points[j]].y -
                                points[stripe_points[i]].y) < dist;
           ++j) {
        dist = min(dist, euclid_dist(points[stripe_points[i]],
                                     points[stripe_points[j]]));
      }
    }

    return dist;
  };

  cout << get_ans(get_ans, sorted_x, sorted_y);
}