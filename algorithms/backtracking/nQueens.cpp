//Compile: g++ -g -Wshadow -Wall main.cpp -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cpp -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cpp -o a.exe -Ofast -Wno-unused-result && a.exe

#pragma GCC optimize("Ofast")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<long, long> pl;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::vector<pii> vpii;
typedef std::vector<pl> vpl;
typedef std::vector<vi> vvi;
typedef std::vector<vl> vvl;
typedef std::map<int, int> mii;
typedef std::priority_queue<int> pqd;
typedef std::priority_queue<int, vi, std::greater<int>> pqi;

#define eb emplace_back
#define F first
#define S second
#define MOD (long long)1e9 + 7
#define PI 3.14159265358979323846
#define INF __builtin_inff()

#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define deb(x) cout << '\n' \
                    << #x << " = " << x << '\n'
#define sortall(x) sort(x.begin(), x.end())
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mk(arr, n, type) type* arr = new type[n]

std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

inline void setup();
inline void solve();

int main(int argc, char* argv[]) {
    setup();

    ll t = 1;

    // std::cin >> t;

    while (t--) solve(), std::cout << '\n';

    return 0;
}

inline void setup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

#ifdef LOCAL_PROJECT  // run with -DLOCAL_PROJECT during compilation
    freopen("input.txt", "r", stdin);
#else
#ifndef ONLINE_JUDGE  // runs automatically for supported online judges
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#endif
}

using namespace std;

void printBoard(bool* board, unsigned short int n) {
    fo(row, n) {
        fo(col, n) {
            if (board[row * n + col] == 1)
                cout << setw(2) << 'Q';
            else
                cout << setw(2) << '_';
        }
        cout << '\n';
    }
}

bool isSafeToPlaceQueen(bool* board, unsigned short int row, unsigned short int col, unsigned short int n) {
    fo(i, row) {
        if (board[i * n + col] == 1) return 0;
    }

    short int x = row;  //  this can not be unsigned as breaking the while loop would not be possible
    short int y = col;

    //  left diagonal
    while (x >= 0 && y >= 0) {
        if (board[x * n + y] == 1) return 0;
        --x;
        --y;
    }

    x = row;
    y = col;

    //  right diagonal
    while (x >= 0 && y < n) {
        if (board[x * n + y] == 1) return 0;
        --x;
        ++y;
    }

    return 1;
}

bool solveNQueen(bool* board, unsigned short int row, unsigned short int n) {
    if (row == n) return 1;

    fo(col, n) {
        if (isSafeToPlaceQueen(board, row, col, n)) {
            board[row * n + col] = 1;

            if (solveNQueen(board, row + 1, n)) return 1;

            board[row * n + col] = 0;  //  backtracking
        }
    }

    return 0;
}

inline void solve() {
    unsigned short int n = 4;

    mk(board, n * n, bool);

    memset(board, 0, n * n);

    if (solveNQueen(board, 0, n))
        printBoard(board, n);
    else
        cout << "Unsolvable Board!";
}
