class Solution {
public:
    Solution(int m, int n) : rows(m), cols(n), maxx(m * n) {
    }
    
    vector<int> flip() {
      int idx = rand() % maxx;
      
      while(se.count(idx)) {
        idx = (idx + 1) % maxx;
      }
      se.insert(idx);
      
      return {idx / cols, idx % cols};
    }
    
    void reset() {
      se.clear();      
    }
private:
  int rows, cols, maxx;
  unordered_set<int> se;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
