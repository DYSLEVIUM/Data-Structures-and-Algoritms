class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        m_st1.push(x);
    }
    
    int pop() {
        if(m_st2.empty()) {
            while(!m_st1.empty()) {
                m_st2.push(m_st1.top());
                m_st1.pop();
            }
        }

        int te = m_st2.top();
        m_st2.pop();

        return te;
    }
    
    int peek() {
        if(m_st2.empty()) {
            while(!m_st1.empty()) {
                m_st2.push(m_st1.top());
                m_st1.pop();
            }
        }
        return m_st2.top();
    }
    
    bool empty() {
        return m_st1.empty() && m_st2.empty();
    }

public:
    stack<int> m_st1, m_st2; // st1 will have be actual stack, while m_st2 will be reversed stack
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
