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
inline void findPrime();

int main(int argc, char* argv[]) {
    setup();

    long long t = 1;
    std::cin >> t;

    findPrime();
    while (t--) solve();

    return 0;
}

//Compile: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cc -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && a.exe

using namespace std;

bool sieve[1000010];

void findPrime() {
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i * i <= 1000010; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= 1000010; j += i) {
                sieve[j] = false;
            }
        }
    }
}

inline void solve() {

    cout<<sieve[2]<<'\n';
    cout<<sieve[3]<<'\n';
}
