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

//	http://codeforces.com/problemset/problem/550/A

inline void solve() {
    string s;
    cin >> s;

    string s1 = "AB";
    string s2 = "BA";

    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == s1[0] && s[i + 1] == s1[1]) {
            for (int j = i + 2; j < s.length() - 1; ++j) {
                if (s[j] == s2[0] && s[j + 1] == s2[1]) {
                    cout << "YES";
                    return;
                }
            }
            break;
        }
    }

    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == s2[0] && s[i + 1] == s2[1]) {
            for (int j = i + 2; j < s.length() - 1; ++j) {
                if (s[j] == s1[0] && s[j + 1] == s1[1]) {
                    cout << "YES";
                    return;
                }
            }
            break;
        }
    }

    cout << "NO";
}
