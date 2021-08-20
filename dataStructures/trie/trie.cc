#define _USE_MATH_DEFINES
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#ifdef DYSLEVIUM
#include "dyslevium.h"
#else
#include <bits/stdc++.h>
#endif

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pl;
typedef std::vector<ll> vl;
typedef std::vector<pl> vpl;
typedef std::vector<vl> vvl;
typedef std::map<ll, ll> mll;
typedef std::priority_queue<ll> pqd;
typedef std::priority_queue<ll, vl, std::greater<ll>> pqi;

#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MOD (ll)(1e9 + 7)

std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());

//  macro functions
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define modAdd(a, b) ((((a % MOD) + (b % MOD)) % MOD) + MOD) % MOD
#define modSub(a, b) ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD
#define modMul(a, b) ((((a % MOD) * (b % MOD)) % MOD) + MOD) % MOD

//  template functions
template <typename T>
inline T gcd(const T& a, const T& b) {
  if (b) return gcd(b, a % b);
  return a;
}
template <typename T>
inline T binPowIter(T x, T n) {
  T res = 1;
  while (n) {
    if (n & 1) res = modMul(res, x);
    x = modMul(x, x);
    n >>= 1;
  }
  return res % MOD;
}
template <typename T>
inline T modInverse(const T& a) { return binPowIter(a, MOD - 2); }
template <typename T>
inline T modDiv(const T& a, const T& b) { return (modMul(a, modInverse(b)) + MOD) % MOD; }

//  debuging
#ifdef DYSLEVIUM
#define deb(x) std::cerr << #x << " = " << x << '\n'
#else
#define deb(x)
#endif

//  initial setup
inline void setup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);

#ifdef DYSLEVIUM
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
  freopen("error.err", "w", stderr);
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
  setup();

  auto startTime = std::chrono::high_resolution_clock::now();

  ll t = 1;
  // std::cin >> t;

  while (t--) solve();

  auto endTime = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

#ifdef DYSLEVIUM
  std::cerr << "\nTime: " << duration.count();
#endif

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

//  also known as prefix tree
class Trie {
  class Node {
    bool isLeaf;

    unordered_map<char, Node*> mp;

    Node() : isLeaf(false) {}

    virtual ~Node() {
      for (auto it : mp) {
        delete it.S;
        it.S = nullptr;
      }
    }

    friend class Trie;
  };

  bool haveChildren() {
    for (auto it : this->root->mp) {
      if (it.S != nullptr) return true;
    }

    return false;
  }

 public:
  Node* root;

  Trie() : root(nullptr) {}

  void insert(string data) {
    //  if the trie is intially empty
    if (this->root == nullptr) this->root = new Node();

    Node* currNode = this->root;

    fo(i, data.size()) {
      //  create a node if the path doesn't exist
      if (currNode->mp.find(data[i]) == currNode->mp.end()) {
        currNode->mp[data[i]] = new Node();
      }

      //  go to next node
      currNode = currNode->mp[data[i]];
    }

    //  after inserting the word, it is valid
    currNode->isLeaf = true;
  }

  bool find(string data) {
    if (this->root == nullptr) return false;

    Node* currNode = this->root;

    fo(i, data.size()) {
      //  if node doesn;t exist, data is not present
      if (currNode->mp.find(data[i]) == currNode->mp.end()) return false;

      currNode = currNode->mp[data[i]];
    }

    return currNode->isLeaf;
  }

  void remove(string data) {
    if (this->root == nullptr) return;

    auto removeHelper = [&](Node* currNode, string data, ll idx = 0, const auto& removeHelper) -> bool {
      //  end of the string
      if ((ll)data.size() == idx && currNode->isLeaf) {
        if (!this->haveChildren()) {
          delete currNode;  //  delete the current node
          currNode = nullptr;
          return true;  //  delete the non-leaf parent nodes
        } else {
          //  mark the current node as a non-leaf node as this is not the end point any more
          currNode->isLeaf = false;
          return false;  //  don't delete its parent nodes
        }
      } else {
        // recur for the node corresponding to the next character in the string and if it returns true, delete the current node if it is non-leaf
        if (currNode->mp.find(data[idx]) != currNode->mp.end() && removeHelper(currNode->mp[data[idx]], data, idx + 1, removeHelper) && currNode->isLeaf == false) {
          if (!this->haveChildren()) {
            delete currNode;
            currNode = nullptr;
            return true;  //  delete the non-leaf parent nodes
          } else
            return false;  //  don't delete its parent nodes
        }
      }

      return false;
    };

    removeHelper(this->root, data, 0, removeHelper);
  }

  ~Trie() {
    delete this->root;
    this->root = nullptr;
  }
};

inline void solve() {
  Trie myTrie;

  vector<string> words = {"pushpa", "umang"};

  for (auto word : words) myTrie.insert(word);

  if (myTrie.find("pushpaa")) {
    cout << "pushpaa found\n";
  } else {
    cout << "pushpaa not found\n";
  }

  if (myTrie.find(words[0])) {
    cout << words[0] << " found\n";
  } else {
    cout << words[0] << " not found\n";
  }

  if (myTrie.find(words[1])) {
    cout << words[1] << " found\n";
  } else {
    cout << words[1] << " not found\n";
  }

  myTrie.remove(words[1]);

  if (myTrie.find(words[1])) {
    cout << words[1] << " found\n";
  } else {
    cout << words[1] << " not found\n";
  }
}
