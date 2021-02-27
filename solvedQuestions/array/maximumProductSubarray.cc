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

//	https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

class Solution {
   public:
    long long maxProduct(int* arr, int n) {
        long long mn = arr[0];
        long long mx = arr[0];

        long long res = arr[0];

        for (int i = 1; i < n; ++i) {
            if (arr[i] < 0) swap(mx, mn);

            mx = max((long long)arr[i], arr[i] * mx);
            mn = min((long long)arr[i], arr[i] * mn);

            res = max(mx, res);
        }

        return res;
    }
};

inline void solve() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution ob;
    auto ans = ob.maxProduct(arr, n);

    cout << ans << "\n";
}
