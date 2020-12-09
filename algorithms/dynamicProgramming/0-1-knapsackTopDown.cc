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
    std::cin >> t;

    while (t--) solve();

    return 0;
}

using namespace std;

//  https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

int dp[100][100];

inline void knapsackTopDown(int* wt, int* val, int w, int n) {
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < w + 1; ++j) {
            if (i == 0 || j == 0) {  //  initialization
                dp[i][j] = 0;
                continue;
            }

            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}

inline void solve() {
    memset(dp, -1, sizeof(dp));

    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;

    int n = sizeof(wt) / sizeof(wt[0]);

    knapsackTopDown(wt, val, w, n);

    cout << dp[n][w];
}
