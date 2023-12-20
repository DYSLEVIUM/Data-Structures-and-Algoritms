class Solution {
public:
    int buyChoco(const vector<int> & prices, const int & money) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static const int num = 2;

        priority_queue<int> max_heap;
        for(const int & price: prices) {
            max_heap.push(price);

            if(max_heap.size() > num) {
                max_heap.pop();
            }
        }

        int cost = 0;
        while(!max_heap.empty()) {
            cost += max_heap.top(); max_heap.pop();
        }

        return money < cost ? money : money - cost;
    }
};
