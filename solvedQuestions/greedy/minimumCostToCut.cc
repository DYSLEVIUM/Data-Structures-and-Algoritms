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

//  https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/

int minimumCostOfBreaking(int X[], int Y[], int m, int n) {
    int cost = 0;

    sort(X, X + m, greater<int>());
    sort(Y, Y + n, greater<int>());

    int horizontalPieces = 1;
    int verticalPieces = 1;

    int iX = 0;
    int iY = 0;

    while (iX < m && iY < n) {
        if (X[iX] > Y[iY]) {
            cost += (X[iX++] * verticalPieces);
            ++horizontalPieces;
        } else {
            cost += (Y[iY++] * horizontalPieces);
            ++verticalPieces;
        }
    }

    int total = 0;
    while (iX < m) total += X[iX++];
    cost += (total * verticalPieces);

    total = 0;
    while (iY < n) total += Y[iY++];
    cost += (total * horizontalPieces);

    return cost;
}

inline void solve() {
    int m = 6, n = 4;
    int X[] = {2, 1, 3, 1, 4};
    int Y[] = {4, 1, 2};
    cout << minimumCostOfBreaking(X, Y, m - 1, n - 1);
}
