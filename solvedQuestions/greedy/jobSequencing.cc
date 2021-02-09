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

//  https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

struct Job {
    int id;
    int dead;
    int profit;
};

pair<int, int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, [](Job j1, Job j2) -> bool {
        return j1.profit > j2.profit;
    });

    int* ganttChart = new int[n]{0};

    for (int i = 0; i < n; ++i) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; --j) {
            if (!ganttChart[j]) {
                ganttChart[j] = arr[i].profit;
                break;
            }
        }
    }

    int cnt = 0, sum = 0;

    for (int i = 0; i < n; ++i) {
        if (ganttChart[i]) {
            ++cnt;
            sum += ganttChart[i];
        }
    }

    delete[] ganttChart;
    return make_pair(cnt, sum);
}

inline void solve() {
    int n;
    cin >> n;

    Job* arr = new Job[n];

    for (int i = 0; i < n; ++i) cin >> arr[i].id >> arr[i].dead >> arr[i].profit;

    pair<int, int> ans = JobScheduling(arr, n);
    cout << ans.first << ' ' << ans.second << '\n';

    delete[] arr;
}
