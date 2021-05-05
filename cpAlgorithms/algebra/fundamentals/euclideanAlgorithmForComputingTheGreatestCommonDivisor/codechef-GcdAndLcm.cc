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
  auto binGCD = [](long long a, long long b) -> long long {
    if (!a || !b) return a | b;

    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    do {
      b >>= __builtin_ctz(b);
      if (a > b) swap(a, b);
      b -= a;
    } while (b);
    return a << shift;
  };

  long long a, b;
  cin >> a >> b;

  long long gc = binGCD(a, b);
  cout << gc << ' ' << a * b / gc << '\n';
}
