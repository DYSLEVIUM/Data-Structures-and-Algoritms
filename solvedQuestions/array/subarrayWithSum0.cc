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

//	https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#

bool subArrayExists(int arr[], int n) {
    unordered_set<int> s;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];

        if (s.find(sum) != s.end() || arr[i] == 0 || sum == 0) return true;
        s.insert(sum);
    }

    return false;
}

inline void solve() {
    int arr[] = {4, 2, -3, 1, 6};
    // int arr[] = {4, 2, 0, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << subArrayExists(arr, n);
}
