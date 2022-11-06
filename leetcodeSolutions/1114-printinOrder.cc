// https://www.codeproject.com/articles/598695/cplusplus11-threads-locks-and-condition-variables
class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(m_mtx);
        while(m_count != 1) m_cv.wait(lck); // wait
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        m_count = 2;
        m_cv.notify_all(); // signal
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(m_mtx);
        while(m_count != 2) m_cv.wait(lck); // wait
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        m_count = 3;
        m_cv.notify_all(); // signal
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(m_mtx);
        while(m_count != 3) m_cv.wait(lck); // wait

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
  
        m_count = 1;
        m_cv.notify_all(); // signal
    }
private:
    int m_count = 1;
    mutex m_mtx;
    condition_variable m_cv;
};
