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
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}

//Compile: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cc -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && a.exe

using namespace std;

//  https://practice.geeksforgeeks.org/problems/valid-substring0624/1

int findMaxLen(string s) {
    stack<char> st;

    int ans = 0;

    int l, r;
    l = r = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == ')')
            ++r;
        else
            ++l;

        if (l == r) ans = max(ans, l);

        if (r > l) l = r = 0;
    }

    for (int i = (int)s.length(); i >= 0; --i) {
        if (s[i] == ')')
            ++r;
        else
            ++l;

        if (l == r) ans = max(ans, l);

        if (l > r) l = r = 0;
    }

    return ans << 1;
}

inline void solve() {
    string s;
    cin >> s;

    cout << findMaxLen(s) << '\n';
}
