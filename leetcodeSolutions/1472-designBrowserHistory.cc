class BrowserHistory {
public:
    BrowserHistory(const string &homepage) {
        m_history.push_back(homepage);
    }
    
    void visit(const string &url) {
        if(m_history.size() == m_ptr + 1) {
            m_history.push_back(url);
        } else {
            m_history[m_ptr + 1] = url;
        }
        
        m_valid = ++m_ptr;
    }
    
    string back(const int &steps) {
        m_ptr = max(0, m_ptr - steps);
        return m_history[m_ptr];
    }
    
    string forward(const int &steps) {
        m_ptr = min(m_valid, m_ptr + steps);
        return m_history[m_ptr];
    }

private:
    int m_ptr = 0, m_valid = 0;
    vector<string> m_history;
};


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
