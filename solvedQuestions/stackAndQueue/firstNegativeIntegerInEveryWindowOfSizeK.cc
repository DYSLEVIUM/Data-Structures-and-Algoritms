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

//	https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0#

inline void solve() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) cin >> arr[i];

    int k;
    cin >> k;

    int* res = new int[n - k + 1]{0};

    stack<int> s;
    for (int i = n - 1; i >= 0; --i)
        if (arr[i] < 0) s.push(i);

    for (int i = 0; i < n - k + 1; ++i) {
        while (!s.empty() && s.top() < i) s.pop();
        if (!s.empty() && s.top() > i + k - 1)
            res[i] = 0;
        else if (!s.empty())
            res[i] = arr[s.top()];
        else
            res[i] = 0;
    }

    for (int i = 0; i < n - k + 1; ++i) cout << res[i] << ' ';
    cout << '\n';
}
