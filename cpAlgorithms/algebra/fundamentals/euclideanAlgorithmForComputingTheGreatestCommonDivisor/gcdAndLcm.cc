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
  //  * GCD
  /*
    * algorithm
      GCD(a, b) = a if b = 0; GCD(b, a % b) otherwise
  */

  //  * implementation
  //  recursive GCD
  auto gcdRecur = [](long long a, long long b, auto&& gcdRecur) -> long long {
    if (b == 0) return a;
    return gcdRecur(b, a % b, gcdRecur);
  };

  deb(gcdRecur(10, 20, gcdRecur));

  //  iterative GCD
  auto gcdIter = [](long long a, long long b) -> long long {
    while (b) {
      a %= b;
      swap(a, b);
    }
    return a;
  };

  deb(gcdIter(10, 20));

  //  * LCM
  /*
    * Algorithm
      LCM(a, b) = a * b / GCD(a, b)
  */

  //  * implementation
  //  LCM
  auto lcm = [&gcdIter](long long a, long long b) -> long long {
    return a * b / gcdIter(a, b);
  };

  deb(lcm(10, 20));

  //  * binary GCD
  /*
    * algorithm
      1. if 2 | a and 2 | b => GCD(a, b) = 2GCD(a/2, b/2)
      2. if 2 | a and b & 1 => GCD(a, b) = GCD(a/2, b)
      3. if a & 1 and b & 1 => GCD(a, b) = GCD(b, a - b)
  */

  //  * implementation
  //  binary GCD
  auto binGCD = [](long long a, long long b) -> long long {
    if (!a || !b) return a | b;

    //  getting the least number of trailing zeros of either the numbers
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    do {
      b >>= __builtin_ctz(b);
      if (a > b) swap(a, b);
      b -= a;
    } while (b);
    return a << shift;
  };

  deb(binGCD(10, 20));

  /*
    * NOTE: there are mainly four important built-in functions in GCC
    1.  __builtin_popcount(x): this function is used to count the number of set bits in an integer
    
    2.  __builtin_parity(x): this function returns 1 if the number has odd parity else it returns 0 for even parity

    3.  __builtin_clz(x): this function is used to count the leading zeros of the integer. Here, clz = count leading zero’s

    4.  __builtin_ctz(x): this function is used to count the trailing zeros of the given integer. Here, ctz = count trailing zeros

    * for all these functions, there is appropriate functions for other data types, e.g., __builtin_ctzl(x), __builtin_ctzll(x) for long and long long respectively
  */
}
