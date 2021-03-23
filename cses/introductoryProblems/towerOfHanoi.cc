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

vector<pair<long long, long long>> ans;

void towerOfHanoi(long long n, long long src, long long help, long long dest) {
    if (n == 1) {
        ans.push_back({src, dest});
        return;
    }

    towerOfHanoi(n - 1, src, dest, help);  //  move n-1 disks to helper with the help of destination
    ans.push_back({src, dest});            //  move the nth disk to the destination
    towerOfHanoi(n - 1, help, src, dest);  //  move the n-1 disk from helper to destination with the help of source
}

inline void solve() {
    long long n;
    cin >> n;

    towerOfHanoi(n, 1, 2, 3);

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.first << ' ' << x.second << '\n';
}
