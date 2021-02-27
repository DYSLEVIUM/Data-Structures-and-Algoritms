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
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}

//Compile: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cc -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && ./a.exe

using namespace std;

//	https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0#

inline void solve() {
    int n;
    cin >> n;

    const int N = 1e5;
    int* res = new int[N]{1};

    int resSize = 1;

    for (int i = 2; i <= n; ++i) {
        int carry = 0;

        for (int j = 0; j < resSize; ++j) {
            int prod = res[j] * i + carry;

            res[j] = prod % 10;
            carry = prod / 10;
        }

        while (carry) {
            res[resSize] = carry % 10;
            carry /= 10;
            ++resSize;
        }
    }

    for (int i = resSize - 1; i >= 0; --i) cout << res[i];
    cout << '\n';
}
