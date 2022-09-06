class MyHashSet {
public:
    MyHashSet() {
      se.resize(BUCKETS);
    }
    
    void add(int key) {      
      if(contains(key)) {
        return ;
      }
      
      int hash = hash_fun(key);
      se[hash].push_back(key);
    }
    
    void remove(int key) {
      if(!contains(key)) {
        return ;
      }
      
      int hash = hash_fun(key);
      se[hash].erase(search(key));
    }
    
    bool contains(int key) {
      int hash = hash_fun(key);
      return search(key) != se[hash].end();
    }
private:
  // we use chaining here, when get a collision, we could have also used linear probing or quadratic probing
  vector<list<int>> se;
  const int BUCKETS = 1e2;

  int hash_fun (int key) {
      return key % BUCKETS;
  }
  
  list<int>::iterator search(int key) {
    int hash = hash_fun(key);
    return find(se[hash].begin(), se[hash].end(), key);
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
