class MedianFinder {
    priority_queue<int> _max_heap;
    priority_queue<int, vector<int>, greater<int>> _min_heap;

  public:
    MedianFinder() {}
    
    void addNum(const int& num) {
      if(_max_heap.size() > _min_heap.size()) _min_heap.push(num);
      else _max_heap.push(num);
      
      if(!_min_heap.empty()){
        //  fixing the order
        if(_max_heap.top() > _min_heap.top()){
          int mx = _max_heap.top();
          int mn = _min_heap.top();

          _max_heap.pop();
          _min_heap.pop();

          _max_heap.push(mn);
          _min_heap.push(mx);
        }
      }    
    }
    
    double findMedian() {
      if(_max_heap.size() == _min_heap.size()){
        return double(_max_heap.top() + _min_heap.top()) / 2.0;
      }else{
        return _max_heap.size() > _min_heap.size() ? _max_heap.top() : _min_heap.top();
      }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
