class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        m_req.push_back(t);

        int lb = lower_bound(m_req.begin(), m_req.end(), t - 3000) - m_req.begin();
        return m_req.size() - lb;
    }
private:
    vector<int> m_req;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
