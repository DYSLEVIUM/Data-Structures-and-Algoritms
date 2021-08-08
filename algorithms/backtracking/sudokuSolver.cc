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

void printBoard(unsigned short int* board) {
    fo(i, 9) {
        fo(j, 9) {
            cout << setw(2) << board[i * 9 + j] << ' ';
        }
        cout << '\n';
    }
}

bool canPlace(unsigned short int* board, unsigned short int r, unsigned short int c, unsigned short int n) {
    if (board[r * 9 + c] != 0) return 0;

    fo(i, 9) {
        if (board[i * 9 + c] == n) return 0;
        if (board[r * 9 + i] == n) return 0;
    }

    unsigned short int sRow = r - (r % 3);
    unsigned short int sCol = c - (c % 3);

    Fo(i, sRow, sRow + 3) {
        Fo(j, sCol, sCol + 3) {
            if (board[i * 9 + j] == n) return 0;
        }
    }

    return 1;
}

bool solveSudoku(unsigned short int* board, unsigned short int r, unsigned short int c) {
    if (r == 9) return 1;

    if (c == 9) return solveSudoku(board, r + 1, 0);

    if (board[r * 9 + c] != 0) return solveSudoku(board, r, c + 1);

    fo(i, 9) {
        if (canPlace(board, r, c, i + 1)) {
            board[r * 9 + c] = i + 1;

            if (solveSudoku(board, r, c + 1)) return 1;

            board[r * 9 + c] = 0;
        }
    }

    return 0;
}

inline void solve() {
    unsigned short int* board = new unsigned short int[9 * 9]{
        4, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 9, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 7, 8, 5,
        0, 0, 7, 0, 4, 8, 0, 5, 0,
        0, 0, 1, 3, 0, 0, 0, 0, 0,
        0, 0, 6, 0, 7, 0, 0, 0, 0,
        8, 6, 0, 0, 0, 0, 9, 0, 3,
        7, 0, 0, 0, 0, 5, 0, 6, 2,
        0, 0, 3, 7, 0, 0, 0, 0, 0};

    if (solveSudoku(board, 0, 0)) {
        printBoard(board);
        return;
    }

    cout << "Unsolvable Board!";
}
