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

//	https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

class Solution {
    // Function to find the trapped water between the blocks.
   public:
    int trappingWater(int* arr, int n) {
        // Code here

        int mxL = 0;
        int mxLI = 0;

        int* mL = new int[n];

        for (int i = 0; i < n; ++i) {
            if (mxL < arr[i]) {
                mxL = arr[i];
                mxLI = i;
            }
            mL[i] = mxLI;
        }

        int mxR = 0;
        int mxRI = n - 1;

        int* mR = new int[n];

        for (int i = n - 1; i >= 0; --i) {
            if (mxR < arr[i]) {
                mxR = arr[i];
                mxRI = i;
            }
            mR[i] = mxRI;
        }

        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += (min(arr[mL[i]], arr[mR[i]]) - arr[i]);
        }

        delete[] mL;
        delete[] mR;
        return sum;
    }
};

inline void solve() {
    int n;

    //size of array
    cin >> n;

    int* a = new int[n];

    //adding elements to the array
    for (int i = 0; i < n; i++) cin >> a[i];

    Solution obj;
    //calling trappingWater() function
    cout << obj.trappingWater(a, n) << '\n';
}
