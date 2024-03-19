#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int leastInterval(const vector<char> & tasks, const int & n) {
        constinit static const int CHAR_SET = 26;
        
        int fa[CHAR_SET]{};
        for(const char & task: tasks) {
            ++fa[task - 'A'];
        }

        sort(fa, fa + CHAR_SET);

        int chunk = fa[CHAR_SET - 1] - 1; // greatest, first and last element in the schedule will be the biggest one, middle gaps only
        int gaps = chunk * (n + 1); // n + 1 gaps required

        for(int i = CHAR_SET - 1; i >= 0; --i) {
            gaps -= min(chunk, fa[i]); // doing min, throw-away at last block
        }

        int sz = tasks.size();
        return max(sz, sz + gaps);
    }
};

class Solution1 {
public:
    int leastInterval(const vector<char> & tasks, const int & n) {
        constinit static const int CHAR_SET = 26;
        
        int fa[CHAR_SET]{};
        for(const char & task: tasks) {
            ++fa[task - 'A'];
        }

        priority_queue<int> max_heap;
        for(int i = 0; i < CHAR_SET; ++i) {
            if(!fa[i]) {
                continue;
            }
            max_heap.push(fa[i]);
        }

        int ans = 0;
        while(!max_heap.empty()) {
            int cycle = n + 1;

            vector<int> next_batch;
            next_batch.reserve(cycle);
            
            while(cycle && !max_heap.empty()) {
                ++ans, --cycle;
                auto tp = max_heap.top();
                max_heap.pop();

                if(tp == 1) {
                    continue;
                }
                next_batch.push_back(tp - 1);
            }

            for(const int & task: next_batch) {
                max_heap.push(task);
            }

            if(max_heap.empty()) {
                break;
            }

            ans += cycle; // add remaining idle phases
        }

        return ans;
    }
};
