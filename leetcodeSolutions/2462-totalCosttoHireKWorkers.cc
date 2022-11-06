class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        
        int p1 = 0, p2 = n - 1;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap_le, min_heap_ri;
        while(k--) {
            while(p1 <= p2 && min_heap_le.size() != candidates) min_heap_le.push(costs[p1++]);
            while(p1 <= p2 && min_heap_ri.size() != candidates) min_heap_ri.push(costs[p2--]);

            int le = min_heap_le.size() ? min_heap_le.top() : INT_MAX;
            int ri = min_heap_ri.size() ? min_heap_ri.top() : INT_MAX;
            
            if(le <= ri) sum += le, min_heap_le.pop();
            else sum += ri, min_heap_ri.pop();
        }
        
        return sum;
    }
};
