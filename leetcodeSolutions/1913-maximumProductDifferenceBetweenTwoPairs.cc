class Solution {
public:
    int maxProductDifference(const vector<int> & nums) {
        cin.tie(nullptr)->sync_with_stdio(false);

        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int> max_heap;

        for(const int & num : nums) {
            min_heap.push(num), max_heap.push(num);
            if(min_heap.size() > 2) {
                min_heap.pop(), max_heap.pop();
            }
        }

        int prod1 = 1, prod2 = 1;
        while(!min_heap.empty()) {
            prod1 *= min_heap.top(); min_heap.pop(); 
            prod2 *= max_heap.top(); max_heap.pop(); 
        }

        return prod1 - prod2;
    }
};
