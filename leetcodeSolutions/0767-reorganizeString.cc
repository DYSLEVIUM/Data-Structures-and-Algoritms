class Solution {
public:
    string reorganizeString(string s) {
        const int CHAR_SET = 26;
        int n = s.length();
        
        int *fa = new int[CHAR_SET]{ 0 }, mx_cnt = 0;
        for(auto &ch : s) {
            int idx = ch - 'a';
            ++fa[idx];
            mx_cnt = max(mx_cnt, fa[idx]);
        }
        
        // impossible condition when mx_cnt is more than half
        if(mx_cnt > (n + 1) / 2) {
            return "";
        }
        
        using PCI = pair<int, char>;
        priority_queue<PCI> max_heap;
        
        for(int i = 0; i < CHAR_SET; ++i) {
            if(fa[i]) {
                max_heap.push({ fa[i], i + 'a' });
            }
        }
        delete[] fa;
        
        string ans = "";
        while(max_heap.size() > 1) {
            PCI tp1 = max_heap.top();
            max_heap.pop();
            
            PCI tp2 = max_heap.top();
            max_heap.pop();
            
            ans += tp1.second;
            ans += tp2.second;
            
            --tp1.first, --tp2.first;

            if(tp1.first) {
                max_heap.push(tp1);
            }
            
            if(tp2.first) {
                max_heap.push(tp2);
            }
        }
        
        if(!max_heap.empty()) {
            ans += max_heap.top().second;
        }
        
        return ans;
    }
};
