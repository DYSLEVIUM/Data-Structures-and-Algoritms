class SeatManager {
public:
//     set<int> s;
  
//     SeatManager(int n) {
//       for(int i=0;i<n;++i) s.insert(i+1);
//     }
    
//     int reserve() {
//       int top = *s.begin();
//       s.erase(s.begin());
//       return top;
//     }
    
//     void unreserve(int seatNumber) {
//       s.insert(seatNumber);  
//     }
  
    priority_queue<int,vector<int>,greater<int>> minHeap;
  
    SeatManager(int n) {
      for(int i=0;i<n;++i) minHeap.push(i+1);
    }
    
    int reserve() {
      int top = minHeap.top();
      minHeap.pop();
      return top;
    }
    
    void unreserve(int seatNumber) {
      minHeap.push(seatNumber);  
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
