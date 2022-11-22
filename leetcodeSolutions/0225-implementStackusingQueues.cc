class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        m_qu1.push(x);
        int sz = m_qu1.size();
        while(sz--) m_qu1.push(m_qu1.front()), m_qu1.pop();
    }
    
    int pop() {
        int te = m_qu1.front();
        m_qu1.pop();
        return te;
    }
    
    int top() {
        int te = m_qu1.front();
        m_qu1.pop();
        return te;
    }
    
    bool empty() {
        return m_qu1.empty();
    }
private:
    queue<int> m_qu1;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
