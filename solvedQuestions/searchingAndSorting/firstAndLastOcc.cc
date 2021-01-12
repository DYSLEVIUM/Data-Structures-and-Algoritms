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
    freopen("output.txt", "w", stdout);
#endif
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
    setup();

    long long t = 1;
    std::cin >> t;

    while (t--) solve();

    return 0;
}

//Compile: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cc -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && a.exe

using namespace std;
//  https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0#

int bsr(int* a, int x, int low, int high) {
    int idx = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == x) {
            idx = mid;
        }
        if (a[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return idx;
}

int bsl(int* a, int x, int low, int high) {
    int idx = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == x) {
            idx = mid;
        }
        if (a[mid] >= x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return idx;
}

inline void solve() {
    int n, x;
    cin >> n >> x;

    int* a = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int low = 0;
    int high = n - 1;

    if (bsl(a, x, low, high) != -1) {
        cout << bsl(a, x, low, high) << ' ' << bsr(a, x, low, high) << '\n';
    } else
        cout << -1 << '\n';
}
