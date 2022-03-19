class FreqStack {
public:
    FreqStack() {
    }
    
    void push(int val) {
      ++freq[val];
      max_freq = max(max_freq, freq[val]);
      group[freq[val]].push(val);
    }
    
    int pop() {
      int val = group[max_freq].top();
      group[max_freq].pop();
      --freq[val];
      
      //  it can be seen that the next max_freq will be just one less, if this frequency group has no items
      if(group[max_freq].empty()) --max_freq;
      
      return val;
    }
private:
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> group; //  grouping based on the frequency
  int max_freq = 0;
};

// class FreqStack {
// public:
//     FreqStack() {
//     }
    
//     void push(int val) {
//       max_heap.push({++freq[val], {++in_time, val}});
//     }
    
//     int pop() {
//       int val = max_heap.top().second.second;
//       max_heap.pop();
      
//       --freq[val];
      
//       return val;
//     }
// private:
//   priority_queue<pair<int, pair<int, int>>> max_heap;
//   unordered_map<int, int> freq;
//   int in_time = 0;
// };

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
