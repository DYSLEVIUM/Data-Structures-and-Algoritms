//Compile: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cc -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && a.exe

#pragma GCC optimize("Ofast,fast-math")

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define deb(x) cout << '\n' \
                    << #x << " = " << x << '\n'

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

//  https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

int dp[100][100];

inline int knapsack(int* wt, int* val, int w, int n) {
    if (n == 0 || w == 0) return 0;

    if (dp[n][w] != -1) return dp[n][w];

    if (wt[n - 1] <= w) {
        return dp[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
    } else {
        return dp[n][w] = knapsack(wt, val, w, n - 1);
    }
}

inline void solve() {
    memset(dp, -1, sizeof(dp));

    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;

    int n = sizeof(wt) / sizeof(wt[0]);

    cout << knapsack(wt, val, w, n);
}
