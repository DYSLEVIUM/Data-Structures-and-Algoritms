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

//	https://www.geeksforgeeks.org/merging-intervals/

inline void solve() {
    pair<int, int> intervals[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};

    int size = sizeof(intervals) / sizeof(intervals[0]);

    if (size == 0) return;

    sort(intervals, intervals + size, [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.first < b.first;
    });

    stack<pair<int, int>> s;

    s.push(intervals[0]);

    for (int i = 1; i < size; ++i) {
        if (s.top().second < intervals[i].first)
            s.push(intervals[i]);
        else if (s.top().second <= intervals[i].second) {
            s.top().second = intervals[i].second;
        }
    }

    while (!s.empty()) {
        deb(s.top().first);
        deb(s.top().second);
        s.pop();
    }
}
