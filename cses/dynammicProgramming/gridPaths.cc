#define _USE_MATH_DEFINES
#pragma GCC optimize("Ofast,fast-math")

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
#define MOD (ll)1e9 + 7
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
    // freopen("output.txt", "w", stdout);
#endif
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
    setup();

    ll t = 1;
    // std::cin >> t;

    while (t--)
        solve();

    return 0;
}

using namespace std;
//  Compile and run: g++ -g -Wshadow -Wall practice.cpp -o a.exe -Ofast -Wno-unused-result && ./a.exe

inline void solve() {
    ll n;
    cin >> n;

    mk(g, n, char*);
    fo(i, n) g[i] = new char[n];

    fo(i, n) fo(j, n) cin >> g[i][j];

    if (n == 1 && g[0][0] == '.') {
        cout << 1;
        return;
    }

    mk(dp, n, ll*);
    fo(i, n) dp[i] = new ll[n];

    fo(i, n) {
        if (g[i][0] == '*')
            break;
        else
            dp[i][0] = 1;
    }

    fo(i, n) {
        if (g[0][i] == '*')
            break;
        else
            dp[0][i] = 1;
    }

    dp[0][0] = 0;

    Fo(i, 1, n) {
        Fo(j, 1, n) {
            if (g[i][j] == '*') continue;
            if (g[i - 1][j] != '*')
                dp[i][j] += dp[i - 1][j];
            if (g[i][j - 1] != '*')
                dp[i][j] += dp[i][j - 1];

            dp[i][j] %= MOD;
        }
    }
    cout << dp[n - 1][n - 1];
}
