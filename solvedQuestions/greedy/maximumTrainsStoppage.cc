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
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && a.exe

using namespace std;

//  https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/

class train {
   public:
    int stTime, etTime, platNo;
};

int maxStop(train* arr, int m) {
    sort(arr, arr + m, [](train a, train b) {
        if (a.platNo == b.platNo) return a.etTime < b.etTime;
        return a.platNo < b.platNo;
    });

    int cnt = 0;
    for (int i = 0; i < m - 1; ++i) {
        int t = i;
        while (arr[t].platNo == arr[i + 1].platNo && arr[t].etTime > arr[i + 1].stTime) {
            ++cnt;
            ++i;
        }
    }
    return m - cnt;
}

inline void solve() {
    int n, m;
    cin >> n >> m;

    train* arr = new train[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr[i].stTime >> arr[i].etTime >> arr[i].platNo;
    }

    cout << "Maximum Stopped Trains = "
         << maxStop(arr, m) << '\n';
}
