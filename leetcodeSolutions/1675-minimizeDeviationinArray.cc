class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        constexpr int INF = 0x3f3f3f3f;
        
        int res = INF, minn = INF;

        priority_queue<int> max_heap;
        for(int & num : nums) {
            num = num & 1 ? num << 1 : num;
            max_heap.push(num);
            minn = min(minn, num);
        }

        while(max_heap.top() % 2 == 0) {
            int tp = max_heap.top();

            res = min(res, tp - minn);
            minn = min(minn, tp / 2);
            max_heap.push(tp / 2);
            max_heap.pop();
        }

        return min(res, max_heap.top() - minn);
    }
};
