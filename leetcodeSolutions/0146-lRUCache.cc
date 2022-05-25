class LRUCache {
public:
    LRUCache(int capacity): m_capacity(capacity) {}
    
    int get(int key) {
        auto it = m_cache.find(key);
        if(it == m_cache.end()) return -1;
        touch(it);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m_cache.find(key);
        
        if(it != m_cache.end()) {
            touch(it);
            li.begin()->second = value; //  update with new value
        }
        else {
            if(m_cache.size() == m_capacity) {
                m_cache.erase(li.back().first);
                li.pop_back();
            }
            li.push_front({key, value});
        }
        
        m_cache[key] = li.begin();
    }
    
private:
    using LPI = list<pair<int, int>>;
    using MPI = unordered_map<int, LPI::iterator>;
    
    const int m_capacity;
    LPI li;    //  we keep both the key and the value, so that we can erase the key from the hashmap
    MPI m_cache;
    
    void touch(MPI::iterator it) {
        int key = it->first;
        int value = it->second->second;
        auto iter = it->second;
        
        li.erase(iter);  //  delete the node from the initial position in the doubly linked list  
        li.push_front({key, value});   //  make new node as the head
        m_cache[key] = li.begin();  //  update cache
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
