class FooBar {
private:
    int n;

    int m_cnt = 0;
    mutex m_mtx;
    condition_variable m_cv;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lck(m_mtx);
        for (int i = 0; i < n; i++) {
            while(m_cnt & 1) m_cv.wait(lck);
        	
            // printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
        
            ++m_cnt;
            m_cv.notify_all(); // signal
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lck(m_mtx);
        for (int i = 0; i < n; i++) {
            while(m_cnt % 2 == 0) m_cv.wait(lck);
        	
            // printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            ++m_cnt;
            m_cv.notify_all(); // signal
        }
    }
};
