#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  auto binPowIterMOD = [](long long x, long long n, long long MOD) -> long long {
    long long res = 1;

    while (n) {
      if (n & 1) res = res * x % MOD;

      x = x * x % MOD;
      n >>= 1;
    }

    return res % MOD;
  };
  
  long long t;
  cin>>t;
  
  while(t--){
  	long long a, b;
  	cin >> a >> b;

  	cout << binPowIterMOD(a, b, 10) << '\n';
  }
}
