#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;

        priority_queue<pair<int, char>> max_heap;
        if(a > 0) {
            max_heap.push({a, 'a'});
        }

        if(b > 0) {
            max_heap.push({b, 'b'});
        }

        if(c > 0) {
            max_heap.push({c, 'c'});
        }

        while(!max_heap.empty()) {
            auto [cnt, ch] = max_heap.top();
            max_heap.pop();

            int n = res.size();
            if(n > 1 && res.end()[-1] == res.end()[-2] && res.end()[-1] == ch) {
                if(max_heap.empty()) {
                    break;
                }

                auto [cnt2, ch2] = max_heap.top();
                max_heap.pop();

                res += ch2;
                --cnt2;

                if(cnt2 != 0) {
                    max_heap.push({cnt2, ch2});
                }
            } else {
                res += ch;
                --cnt;
            }

            if (cnt != 0) {
                max_heap.push({cnt, ch});
            }
        }

        return res;
    }
};
