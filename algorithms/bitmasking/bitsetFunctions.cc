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
#define allC(x) x.begin(), x.end()
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

inline void solve() {
    bitset<10> b = 12;     //  0000001100
    cout << b[2] << '\n';  //  1    right-to-left

    cout << b.to_ulong() << '\n';  // decimal number from bitset

    // string to bitset

    string str = "1010101";
    bitset<10> strB(str);
    cout << strB[0] << '\n';           //  1
    string newStr = strB.to_string();  //  string from bitset
    cout << newStr << '\n';

    //  count no of set bits in bitset
    cout << b.count() << '\n';

    //  test function returns 1 if bit is set else it return 0
    cout << "bool representation of " << b << " : ";
    fo(i, (ll)b.size()) cout << b.test(i) << " ";
    cout << '\n';

    //  any function returns true, if atleast 1 bit is set
    if (!b.any())
        cout << "b has no bit set.\n";

    //  check if all bits are set
    if (b.all())
        cout << "b has all bit set.\n";

    //  none function returns true, if none of the bit is set
    if (!b.none()) cout << "b has some bit set\n";

    //  set() sets all bits
    cout << b.set() << '\n';

    //  set(pos, b) makes bset[pos] = b
    cout << b.set(4, 0) << '\n';

    //  set(pos) makes bset[pos] = 1  i.e. default is 1
    cout << b.set(4) << '\n';

    //  reset function makes all bits 0
    cout << b.reset(2) << '\n';
    cout << b.reset() << '\n';

    //  flip function flips all bits i.e.  1 <-> 0 and  0 <-> 1
    cout << b.flip(2) << '\n';
    cout << b.flip() << '\n';

    //  using stream to make multiple bitsets
    string str1 = "10111011101";
    istringstream stream(str1);
    bitset<2> s1;
    bitset<6> s2;
    stream >> s1;
    cout << s1 << '\n';  //  10
    stream >> s2;
    cout << s2 << '\n';  //  111011
}
