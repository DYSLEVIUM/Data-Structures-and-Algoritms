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

//  https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

using namespace std;

int* findTwoElement(int* arr, int n) {
    int* ans = new int[2];

    for (int i = 0; i < n; ++i) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            ans[0] = abs(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) ans[1] = i + 1;
    }

    return ans;
}

inline void solve() {
    int n;
    cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; ++i) cin >> a[i];

    auto ans = findTwoElement(a, n);
    cout << ans[0] << ' ' << ans[1] << '\n';
}
