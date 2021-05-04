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

void solve() {
  auto binPowIterMOD = [](long long x, long long n, long long MOD) -> long long {
    long long res = 1;

    while (n) {
      if (n & 1) res = res * x % MOD;

      x = x * x % MOD;
      n >>= 1;
    }

    return res;
  };

  long long n, k;
  cin >> n >> k;

  //  * for first three digits
  //  n^k = 10^(k * log10(n))
  long double pw = double(k) * log10(n);

  //  getting the extra digits after the decimal and the first two
  pw = 2 + (pw - floor(pw));
  long long l = pow(10, pw);

  //  * for last three digits
  long long r = binPowIterMOD(n, k, 1000);

  printf("%lld...%03lld\n", l, r);
}
