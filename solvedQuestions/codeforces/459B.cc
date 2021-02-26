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

//	http://codeforces.com/problemset/problem/459/B

inline void solve() {
    //	O(1) memory with TLE
    // unsigned long long n;
    // cin >> n;

    // auto cmp = [](const pair<unsigned long long, unsigned long long>& a, const pair<unsigned long long, unsigned long long>& b) -> bool {
    //     return a.first > b.first;
    // };

    // set<pair<unsigned long long, unsigned long long>, decltype(cmp)> s(cmp);

    // for (unsigned long long i = 0; i < n; ++i) {
    //     unsigned long long el;
    //     cin >> el;

    //     auto it = find_if(s.begin(), s.end(), [&](const pair<unsigned long long, unsigned long long>& p) -> bool { return p.first == el; });

    //     if (it != s.end()) {
    //         unsigned long long tempCnt = it->second + 1;
    //         s.erase(it);
    //         s.insert({el, tempCnt});
    //     } else {
    //         s.insert({el, 1});
    //     }
    // }

    // unsigned long long diff = s.begin()->first - s.rbegin()->first;
    // unsigned long long comb = s.begin()->second * s.rbegin()->second;

    // if (s.size() == 1)
    //     comb = s.begin()->second * (s.begin()->second - 1) / 2;
    // cout << diff << ' ' << comb;

    long long n;
    cin >> n;

    long long* b = new long long[n]{0};

    long long mx = LONG_LONG_MIN;
    long long mn = LONG_LONG_MAX;

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        mx = max(mx, b[i]);
        mn = min(mn, b[i]);
    }

    long long cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        cnt1 += (mx == b[i]);
        cnt2 += (mn == b[i]);
    }

    cout << mx - mn << ' ' << (mx == mn ? cnt1 * (cnt1 - 1) / 2 : cnt1 * cnt2);
}
