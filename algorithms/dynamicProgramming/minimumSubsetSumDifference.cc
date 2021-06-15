#define _USE_MATH_DEFINES
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

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

#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MOD (long long)(1e9 + 7)
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
//  Compile and run: g++ -g -Wshadow -Wall practice.cpp -DLOCAL_PROJECT -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  vl arr{1, 2, 7};

  auto findMinimumSubsetSumDifference = [](vl& ar) -> ll {
    ll sum = accumulate(allC(ar), 0);
    ll ans = __LONG_LONG_MAX__;

    vector<vector<bool>> dp(ar.size() + 1, vector<bool>(sum + 1));

    //  in dp we will store all the possible subset that can be formed using all the elements of the array
    fo(i, ar.size() + 1) {
      fo(j, sum + 1) {
        if (i == 0 || j == 0) {
          if (i == 0)
            dp[i][j] = false;
          if (j == 0)
            dp[i][j] = true;
          continue;
        }
        if (j - ar[i - 1] >= 0)
          dp[i][j] = dp[i - 1][j - ar[i - 1]] || dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    //  s1 + s2 = sum => s2 = sum - s1
    //  we limit the s1 to be halfway of the sum so sum - s1 => s2 will be greater than s1
    //  so we need to minimize the difference => s2 - s1 => sum - s1 - s1 is to be minimized
    fo(j, (sum + 1) / 2 + 1) {
      if (dp[ar.size()][j]) {
        ans = min(ans, sum - 2 * j);
      }
    }

    return ans;
  };

  cout << findMinimumSubsetSumDifference(arr) << '\n';
}
