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
    // std::cin >> t;

    while (t--)
        solve();

    return 0;
}

//Compile: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cc -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && ./a.exe

using namespace std;

//	https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

bool areRotations1(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    string temp = s1 + s1;

    return (temp.find(s2) != string::npos);
}

bool areRotations2(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    auto idx = s1.find(s2[0]);

    string s3;

    int t = s1.length();
    while (t) {
        s3 += (s1[(s1.length() - t + idx) % s1.length()]);
        --t;
    }

    return s3 == s2;
}

inline void solve() {
    string s1 = "AACD";
    string s2 = "ACDA";

    cout << (areRotations2(s1, s2) ? "Yes" : "No");
}
