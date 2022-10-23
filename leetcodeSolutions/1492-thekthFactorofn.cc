class Solution {
public:
    int kthFactor(int n, int k) {
        int sq = sqrt(n);
        for(int i = 1; i <= sq; ++i) {
            if(n % i == 0) --k;
            if(!k) return i;
        }

        for(int i = sq; i >= 1; --i) {
            if(n % i == 0) {
                if(n / i == i) continue;
                
                --k;
                if(!k) return n / i;
            }
        }

        return -1;
    }
};

class Solution1 {
public:
    int kthFactor(int n, int k) {
        priority_queue<int> max_heap;
        for(int i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                max_heap.push(i);
                if(i != n / i) max_heap.push(n / i);
            }

            while(max_heap.size() > k) max_heap.pop();
        }

        return max_heap.size() < k ? -1 : max_heap.top();
    }
};
