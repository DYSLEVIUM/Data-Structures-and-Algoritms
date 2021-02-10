#pragma GCC optimize("Ofast,fast-math")

#include <bits/stdc++.h>

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
    // freopen("output.txt", "w", stdout);
#endif
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
    setup();

    long long t = 1;
    // std::cin >> t;

    while (t--)
        solve();

    return 0;
}

//Compile: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cc -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && a.exe

using namespace std;

//  https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/

int buyMaximumProducts(int n, int k, int* price) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) v[i] = make_pair(price[i], i + 1);

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (k - v[i].first * min(k / v[i].first, v[i].second) > 0) {
            cnt += min((k / v[i].first), v[i].second);
            k -= (v[i].first * min(k / v[i].first, v[i].second));
        }
    }

    return cnt;
}

inline void solve() {
    int price[] = {10, 7, 19};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 45;

    cout << buyMaximumProducts(n, k, price) << '\n';
}
