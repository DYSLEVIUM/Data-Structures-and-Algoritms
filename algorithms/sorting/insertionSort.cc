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
#define MOD (ll)(1e9 + 7)
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

  while (t--) {
    solve();
  }

  return 0;
}

using namespace std;
//  Compile and run: g++ -g -Wshadow -Wall -DLOCAL_PROJECT main.cc -o a.exe
//  -Ofast -Wno-unused-result && ./a.exe

inline void solve() {
  int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  auto printArr = [](int* arr, int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
    cout << '\n';
  };

  auto insertionSort = [](int* arr, int n) {
    //  starting from 2nd element
    //  first element is always sorted
    for (int i = 1; i < n; ++i) {
      int key = arr[i];
      int j = i - 1;

      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        --j;
      }

      arr[j + 1] = key;
    }
  };

  cout << "Before sort: ";
  printArr(arr, n);

  insertionSort(arr, n);

  cout << "After sort: ";
  printArr(arr, n);
}
