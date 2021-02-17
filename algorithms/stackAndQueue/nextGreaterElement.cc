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

//  https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

vector<long long> nextLargerElement(vector<long long> arr, int n) {
    vector<long long> res(n);
    stack<long long> s;

    for (long long i = n - 1; i >= 0; --i) {
        if (s.empty()) {
            res[i] = -1;
            s.push(arr[i]);
        } else if (arr[i] < s.top()) {
            res[i] = s.top();
            s.push(arr[i]);
        } else if (arr[i] > s.top()) {
            while (!s.empty() && arr[i] > s.top()) {
                s.pop();
            }

            if (s.empty()) {
                res[i] = -1;
                s.push(arr[i]);
            } else {
                res[i] = s.top();
                s.push(arr[i]);
            }
        }
    }

    return res;
}

inline void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<long long> res = nextLargerElement(arr, n);
    for (long long i : res) cout << i << ' ';
    cout << '\n';
}
