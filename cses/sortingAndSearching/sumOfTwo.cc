#define _USE_MATH_DEFINES
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
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && ./a.exe

using namespace std;

inline void solve() {
    long long n, x;
    cin >> n >> x;

    vector<pair<long long, long long>> vp(n);
    for (long long i = 0; i < n; ++i) {
        long long y;
        cin >> y;
        vp[i] = {y, i + 1};
    }

    sort(vp.begin(), vp.end(), [](pair<long long, long long> a, pair<long long, long long> b) -> bool {
        return a.first < b.first;
    });

    for (long long i = 0; i < n; ++i) {
        long long low = 0;
        long long high = n - 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid == i) break;

            if (vp[mid].first == x - vp[i].first) {
                cout << vp[mid].second << ' ' << vp[i].second;
                return;
            }

            if (vp[mid].first > x - vp[i].first) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    cout << "IMPOSSIBLE";
}
