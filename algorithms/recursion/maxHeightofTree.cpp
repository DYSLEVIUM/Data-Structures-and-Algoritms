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

template <typename T>
class node {
   public:
    T data;
    node* left;
    node* right;
};

template <typename T>
node<T>* newNode(T data) {
    node<T>* Node = new node<T>();

    Node->data = data;
    Node->left = nullptr;
    Node->right = nullptr;

    return Node;
}

template <typename T>
ll heightOfTree(node<T>* root) {
    if (root == nullptr) return 0;

    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

inline void solve() {
    node<ll>* root = newNode<ll>(1);

    root->left = newNode<ll>(2);
    root->right = newNode<ll>(3);

    root->left->left = newNode<ll>(4);
    root->left->right = newNode<ll>(5);

    cout << heightOfTree(root);

    delete root;
}