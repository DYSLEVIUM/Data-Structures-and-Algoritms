#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> h(n);
  for (int& x : h) cin >> x;

  static constexpr int INF = 0x3f3f3f3f;
  deque<int> dp(k, INF);
  dp[k - 1] = 0;
  for (int i = 1; i < n; ++i) {
    int minn = INF;
    for (int j = 1; j <= k; ++j) {
      if (i - j >= 0) minn = min(minn, dp[k - j] + abs(h[i] - h[i - j]));
    }
    dp.push_back(minn);
    dp.pop_front();
  }

  cout << dp.back() << '\n';
}
