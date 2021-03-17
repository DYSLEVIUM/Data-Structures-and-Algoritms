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
    long long n;
    cin >> n;

    if (n < 4 && n != 1) {
        cout << "NO SOLUTION";
        return;
    }

    long long* x = new long long[n];

    long long temp = 0;
    for (int i = 0; i < n / 2; ++i) x[i] = ++temp, x[n - i - 1] = ++temp;

    if (n & 1) x[n / 2] = n;

    if (n & 1)
        reverse(x + n / 2 + 1, x + n);
    else
        reverse(x, x + n / 2);

    for (int i = 0; i < n; ++i) cout << x[i] << ' ';
}
