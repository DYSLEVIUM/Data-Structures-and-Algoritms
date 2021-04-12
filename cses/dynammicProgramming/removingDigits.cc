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

    mk(dp, n + 1, ll);
    memset(dp, -1, sizeof(ll) * (n + 1));

    dp[0] = 0;

    //  initializing all 1 digit to 1
    Fo(i, 1, min((ll)10, n + 1)) dp[i] = 1;

    auto vDigi = [](ll x) -> vl {
        vl digi;
        while (x) {
            digi.push_back(x % 10);
            x /= 10;
        }

        return digi;
    };

    function<ll(ll)> getAns = [&](ll x) -> ll {
        if (dp[x] != -1) return dp[x];

        auto ve = vDigi(x);

        ll mini = LONG_LONG_MAX;
        tr(it, ve) {
            if (*it == 0) continue;
            if (x - *it >= 0) mini = min(1 + getAns(x - *it), mini);
        }

        dp[x] = mini;
        return dp[x];
    };

    cout << getAns(n);
}
