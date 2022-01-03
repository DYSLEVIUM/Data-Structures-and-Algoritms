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
#define MOD (ll)(1e9 + 7)

#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

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

#ifdef DYSLEVIUM
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
  freopen("error.err", "w", stderr);
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
  setup();

  ll t = 1;
  std::cin >> t;

  while (t--)
    solve();

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  ll newElem = 10;
  //  STACK
  //  We want to modify the stack data structure in such a way, that it possible to find the smallest element in the stack in O(1) time, while maintaining the same asymptotic behavior for adding and removing elements from the stack. Quick reminder, on a stack we only add and remove elements on one end.

  //  To do this, we will not only store the elements in the stack, but we will store them in pairs: the element itself and the minimum in the stack starting from this element and below.

  stack<pl> st;

  //  adding an element to the stack
  ll newMin = st.empty() ? newElem : min(newElem, st.top().second);
  st.push({newElem, newMin});

  //  deleting an element
  ll removedEle = st.top().first;
  st.pop();

  //  finding the minimum
  ll mini = st.top().second;

  //  QUEUE (Method 1)
  deque<ll> q;

  //  finding the minimum
  ll mini = q.front();

  //  adding the element
  while (!q.empty() && q.back() > newElem)
    q.pop_back();

  q.push_back(newElem);

  //  deleting an element
  ll removeEle = 10;

  if (!q.empty() && q.front() == removeEle)
    q.pop_front();

  //  QUEUE (Method 2)
  //  We want to be able to remove elements without knowing which element we have to remove. We can accomplish that by storing the index for each element in the queue. And we also remember how many elements we already have added and removed.
  deque<pl> q2;
  ll cntAdded = 0;
  ll cntRemoved = 0;

  //  finding the minimum
  ll mini = q2.front().first;

  //  adding the element
  while (!q2.empty() && q2.back().first > newElem)
    q2.pop_back();

  q2.push_back({newElem, cntAdded});
  ++cntAdded;

  //  deleting an element
  if (!q2.empty() && q2.front().second == cntRemoved)
    q2.pop_front();
  ++cntRemoved;

  //  QUEUE (Method 3)
  //  Here we consider another way of modifying a queue to find the minimum in O(1) This way is somewhat more complicated to implement, but this time we actually store all elements. And we also can remove an element from the front without knowing its value. The idea is to reduce the problem to the problem of stacks, which was already solved by us. So we only need to learn how to simulate a queue using two stacks. We make two stacks, s1 and s2. Of course these stack will be of the modified form, so that we can find the minimum in O(1). We will add new elements to the stack s1, and remove elements from the stack s2. If at any time the stack s2 is empty, we move all elements from s1 to s2 (which essentially reverses the order of those elements). Finally finding the minimum in a queue involves just finding the minimum of both stacks.Thus we perform all operations in O(1) on average (each element will be once added to stack s1, once transferred to s2, and once popped from s2)

  stack<pl> s1, s2;

  //  finding the minimum
  ll mini;
  if (s1.empty() || s2.empty())
    mini = s1.empty() ? s2.top().second : s1.top().second;
  else
    mini = min(s1.top().second, s2.top().second);

  //  add element
  mini = s1.empty() ? newElem : min(newElem, s1.top().second);
  s1.push({newElem, mini});

  //  removing an element
  if (s2.empty()) {
    while (!s1.empty()) {
      ll element = s1.top().first;
      s1.pop();
      ll minimum = s2.empty() ? element : min(element, s2.top().second);
      s2.push({element, minimum});
    }
  }
  ll removElement = s2.top().first;
  s2.pop();
}
