class StockSpanner {
public:
    StockSpanner() {
        m_st.push(m_curr_idx++);
        m_data.push_back(INT_MAX);
    }
    
    // previous greater element position
    int next(int price) {
        while(!m_st.empty() && m_data[m_st.top()] <= price) m_st.pop();
        
        int ans = m_curr_idx - m_st.top();

        m_st.push(m_curr_idx++);
        m_data.push_back(price);

        return ans;
    }

private:
    int m_curr_idx = 0;
    vector<int> m_data;
    stack<int> m_st;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
