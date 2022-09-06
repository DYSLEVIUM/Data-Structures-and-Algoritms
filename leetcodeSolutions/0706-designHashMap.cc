class MyHashMap {
public:
    MyHashMap() {
      se.resize(BUCKETS);
    }
    
    void put(int key, int value) {
      int hash = hash_fun(key);
      auto it = search(key);
      
      if(it == se[hash].end()) {
        se[hash].push_back({key, value});
        return ;
      }
      
      // update
      it->second = value;
    }
    
    int get(int key) {
      int hash = hash_fun(key);
      auto it = search(key);
      
      if(it == se[hash].end()) {
        return -1;
      }
      
      return it->second;
    }
    
    void remove(int key) {
      int hash = hash_fun(key);
      auto it = search(key);
      
      if(it == se[hash].end()) {
        return ;
      }
      
      se[hash].erase(it);
    }
private:
  using LPII = list<pair<int, int>>;
  vector<LPII> se;
  const int BUCKETS = 1e4;
  
  int hash_fun(const int &key) {
    return key % BUCKETS;
  }
  
  LPII::iterator search(const int &key) {
    int hash = hash_fun(key);
    
    auto it = se[hash].begin();
    while(it != se[hash].end() && it->first != key) {
      ++it;
    }
    
    return it;
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
