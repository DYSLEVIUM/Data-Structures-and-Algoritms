class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> cap_pro(n);
        for(int i = 0; i < n; ++i) {
            cap_pro[i] = {capital[i], profits[i]};
        }

        sort(cap_pro.begin(), cap_pro.end());

        int i = 0;
        priority_queue<int> max_heap;
        while(k--) {
            while(i < n && cap_pro[i].first <= w) {
                max_heap.push(cap_pro[i].second);
                ++i;
            }
            
            if(max_heap.empty()) break;

            w += max_heap.top();
            max_heap.pop();
        }

        return w;
    }
};
