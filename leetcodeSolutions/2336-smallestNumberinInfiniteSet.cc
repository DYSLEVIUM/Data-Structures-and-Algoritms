class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int temp = m_smallest;
        m_removed.insert(m_smallest);
        while(m_removed.count(m_smallest)) {
            ++m_smallest;
        }
        return temp;
    }
    
    void addBack(int num) {
        m_removed.erase(num);
        if(num < m_smallest) {
            m_smallest = num;
        }
    }
private:
    int m_smallest = 1;
    unordered_set<int> m_removed;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
