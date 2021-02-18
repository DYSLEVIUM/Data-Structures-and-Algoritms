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

bool isSorted(int* arr, int sti, int edi, bool isIncreasing = true) {
    if (edi - sti == 1) return true;
    if (sti == 0) {
        if (arr[sti] <= arr[sti + 1])
            isIncreasing = true;
        else if (arr[sti] >= arr[sti + 1])
            isIncreasing = false;
    }

    if (isIncreasing) {
        if (arr[sti] > arr[sti + 1]) return false;
    } else {
        if (arr[sti] < arr[sti + 1]) return false;
    }

    return isSorted(arr, sti + 1, edi, isIncreasing);
}

inline void solve() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << isSorted(arr, 0, n) << '\n';

    reverse(arr, arr + n);
    cout << isSorted(arr, 0, n) << '\n';

    int arr2[] = {2, 3, 1, 4, 5};

    cout << isSorted(arr2, 0, n) << '\n';
}
