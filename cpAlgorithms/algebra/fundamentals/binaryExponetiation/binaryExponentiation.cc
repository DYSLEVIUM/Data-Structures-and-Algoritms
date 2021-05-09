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

inline void solve() {
  /*
			*	Algorithm
			a^(b + c) = a^b . a^c and a^2b = (a^b)^2
			So,
					3^13 = 3^((1101)base2) = 3^(8) . 3^(4) . 3^(1)

			Time Complexity: O(log n) as the number n has exactly floor(log2(n))+1 digits
    */

  //  *	Implementation
  //  recursive binaryExponentiation
  auto binPowRecur = [](long long x, long long n, auto&& binPowRecur) -> long long {
    if (n == 0) return 1;

    long long res = binPowRecur(x, n >> 1, binPowRecur);

    if (n & 1) return res * res * x;
    return res * res;
  };

  deb(binPowRecur(2, 10, binPowRecur));

  //  iterative binaryExponentiation
  auto binPowIter = [](long long x, long long n) -> long long {
    long long res = 1;

    while (n) {
      if (n & 1) res = res * x;

      x *= x;
      n >>= 1;
    }

    return res;
  };

  deb(binPowIter(2, 10));

  //	*	Applications
  //	?	Compute x^n mod m
  auto binPowIter = [](long long x, long long n, long long MOD) -> long long {
    long long res = 1;
    while (n) {
      if (n & 1) res = ((res % MOD) * (x % MOD)) % MOD;

      x = ((x % MOD) * (x % MOD)) % MOD;

      n >>= 1;
    }

    return res % MOD;
  };
  /*	NOTE: if MOD is a prime number, we can speed by the algorithm by calculating x^(n%(MOD-1)) instead of x^n which is a consequent of fermat's little theorem that 
		a^p === a (mod p) => a^(p-1) === 1 (mod p)
		where, p is a prime number.
	*/
}
