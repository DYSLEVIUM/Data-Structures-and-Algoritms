//Compile: g++ -g -Wshadow -Wall main.cpp -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cpp -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cpp -o a.exe -Ofast -Wno-unused-result && a.exe

#pragma GCC optimize("Ofast,fast-math")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
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
#define deb(x) cout << '\n' \
                    << #x << " = " << x << '\n'
#define sortall(x) sort(x.begin(), x.end())
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mk(arr, n, type) type* arr = new type[n]

std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

inline void setup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

#ifdef LOCAL_PROJECT  // run with -DLOCAL_PROJECT during compilation
    freopen("input.txt", "r", stdin);
#else
#ifndef ONLINE_JUDGE  // runs automatically for supported online judges
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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

bool subsetSumExist(ll* arr, ll n, ll sum) {
    mk(dp, (n + 1) * (sum + 1), bool);

    //  if sum is greater than sum of all elements of the array
    if (sum > accumulate(arr, arr + n, 0)) return 0;

    fo(i, n + 1) {
        fo(j, sum + 1) {
            if (i == 0) {
                dp[i * (sum + 1) + j] = 0;
                continue;
            }

            if (j == 0) {
                dp[i * (sum + 1) + j] = 1;
                continue;
            }

            //  if currentSum > element
            if (arr[i - 1] <= j) {
                dp[i * (sum + 1) + j] = dp[i * (sum + 1) + j - arr[i - 1]] || dp[(i - 1) * (sum + 1) + j];  //  we can take the element or not take it
            } else {
                dp[i * (sum + 1) + j] = dp[(i - 1) * (sum + 1) + j];  //  we can not take the element
            }
        }
    }

    bool ans = dp[n * (sum + 1) + sum];

    delete[] dp;

    return ans;
}

inline void solve() {
    ll arr[] = {2, 3, 7, 8, 10};
    ll sum = 11;

    ll n = sizeof(arr) / sizeof(arr[0]);

    cout << (subsetSumExist(arr, n, sum) == 1 ? "Yes" : "No");
}
