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

// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

inline void solve() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(start) / sizeof(start[0]);

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; ++i) {
        v[i] = {start[i], finish[i]};
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second < b.second;
    });

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        ++cnt;
        int temp = i;
        while (i + 1 < n && v[temp].second >= v[i + 1].first) {
            ++i;
        }
    }

    cout << cnt;
}
