class CustomStack {
public:
    CustomStack(int maxSize): m_max_size(maxSize) {
        m_data = new int[m_max_size];
    }
    
    void push(int x) {
        if(m_top + 1 == m_max_size) return; //  stack already full
        m_data[++m_top] = x;
    }
    
    int pop() {
        if(m_top == -1) {
            return -1;
        }
        
        return m_data[m_top--];
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min({m_top + 1, k}); ++i) {
            m_data[i] += val;
        }
    }

private:
    int m_max_size;
    int *m_data;
    int m_top = -1;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
