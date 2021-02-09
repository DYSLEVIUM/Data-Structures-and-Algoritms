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

//  https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

struct Item {
    int value;
    int weight;
};

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, [](Item a, Item b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });

    int i = 0;

    double sum = 0;
    while (W > 0 && i < n) {
        if (W < arr[i].weight) break;

        sum += arr[i].value;
        W -= arr[i].weight;
        ++i;
    }

    //  remaining fraction
    if (i < n) {
        sum += (double(W) * arr[i].value / (double)arr[i].weight);
    }

    return sum;
}

inline void solve() {
    int n, W;
    cin >> n >> W;

    Item* arr = new Item[n];

    for (int i = 0; i < n; ++i) cin >> arr[i].value >> arr[i].weight;

    cout << fractionalKnapsack(W, arr, n) << '\n';
}
