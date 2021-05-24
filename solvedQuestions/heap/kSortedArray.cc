#define _USE_MATH_DEFINES
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<long, long> pl;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::vector<pii> vpii;
typedef std::vector<pl> vpl;
typedef std::vector<vi> vvi;
typedef std::vector<vl> vvl;
typedef std::map<int, int> mii;
typedef std::priority_queue<int> pqd;
typedef std::priority_queue<int, vi, std::greater<int>> pqi;

#define eb emplace_back
#define F first
#define S second
#define MOD (long long)1e9 + 7
#define PI 3.14159265358979323846
#define INF __builtin_inff()

#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define allC(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define deb(x) std::cout << '\n' \
                         << #x << " = " << x << '\n'
#define sortall(x) sort(x.begin(), x.end())
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mk(arr, n, type) type* arr = new type[n]

std::mt19937_64 rng(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());

inline void setup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

#ifdef LOCAL_PROJECT  // run with -DLOCAL_PROJECT during compilation
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
  setup();

  ll t = 1;
  // std::cin >> t;

  while (t--) solve();

  return 0;
}

using namespace std;
//  Compile and run: g++ -g -Wshadow -Wall practice.cpp -o a.exe -Ofast
//  -Wno-unused-result && ./a.exe

inline void solve() {
  int arr[] = {6, 5, 3, 2, 8, 10, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  auto kSorted = [](int* arr, int n, int k) {
    pqi minHeap;

    for (int i = 0; i < n; ++i) {
      minHeap.push(arr[i]);

      if (minHeap.size() > k) {
        arr[i - k] = minHeap.top();
        minHeap.pop();
      }
    }

    int i = n - k - 1;
    while (!minHeap.empty()) {
      arr[++i] = minHeap.top();
      minHeap.pop();
    }
  };

  kSorted(arr, n, 3);

  for (int i = 0; i < n; ++i) {
    cout << arr[i] << ' ';
  }
}
