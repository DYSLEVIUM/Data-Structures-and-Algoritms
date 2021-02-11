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

//  https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/

struct meeting {
    int start;
    int end;
    int pos;
};

void maxMeeting(int s[], int f[], int n) {
    meeting* arr = new meeting[n];

    for (int i = 0; i < n; ++i) {
        arr[i].start = s[i];
        arr[i].end = f[i];
        arr[i].pos = i + 1;
    }

    sort(arr, arr + n, [](meeting a, meeting b) {
        return a.end < b.end;
    });

    vector<int> pos;
    for (int i = 0; i < n - 1; ++i) {
        int temp = i;
        pos.push_back(arr[i].pos);
        while (i + 1 < n && arr[temp].end >= arr[i + 1].start) {
            ++i;
        }
    }

    for (auto x : pos) {
        cout << x << ' ';
    }
}

inline void solve() {
    // Starting time
    int s[] = {1, 3, 0, 5, 8, 5};

    // Finish time
    int f[] = {2, 4, 6, 7, 9, 9};

    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);

    // Function call
    maxMeeting(s, f, n);
}
