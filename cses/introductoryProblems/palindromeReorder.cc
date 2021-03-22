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
    string s;
    cin >> s;

    unordered_map<char, long long> mp;

    for (long long i = 0; i < (long long)s.length(); ++i) ++mp[s[i]];

    bool foundOdd1 = false;
    for (auto x : mp) {
        if (x.second & 1) {
            if (foundOdd1) {
                cout << "NO SOLUTION";
                return;
            }

            foundOdd1 = true;
        }
    }

    string ans;

    for (auto x : mp) {
        if (x.second & 1) continue;
        for (long long i = 0; i < x.second / 2; ++i) ans += x.first;
    }

    string temp = ans;

    for (auto x : mp) {
        if (x.second & 1)
            for (long long i = 0; i < x.second; ++i) ans += x.first;
    }

    reverse(temp.begin(), temp.end());
    cout << ans + temp;
}
