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

//  https://www.geeksforgeeks.org/survival/

int maxProductSubset(int a[], int n) {
    sort(a, a + n);
  
    int cntZ=0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) ++cntZ;
    }
  
    if (cntZ == n) return 0;

    int cntNeg = 0;
    int negIdx = 0;
    int cntZ = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) break;
        if (a[i] == 0) {
          ++cntZ;
          continue;
        }
        ++cntNeg;
        negIdx = i;
    }
  
    if (cntNeg == 1 && cntZ >= 0) return 0;

    int prod = 1;
    if (cntNeg & 1) {
        for (int i = 0; i < negIdx; ++i) prod *= a[i];
        for (int i = negIdx + 1; i < n; ++i) prod *= a[i];
    } else {
        for (int i = 0; i < n; ++i) prod *= a[i];
    }

    return prod;
}

inline void solve() {
    int a[] = {-1, -1, -2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
}
