template <typename T>
class Queue {
   private:
    int64_t t_front;
    int64_t t_back;
    uint64_t t_size;
    T* data;

   public:
    Queue() : t_front(-1), t_back(-1), t_size(5), data(new T[this->t_size]) {
        memset(this->data, 0, this->t_size * sizeof(T));
    }

    Queue(uint64_t size) {
        this->t_front = this->t_back = -1;
        this->t_size = size;

        this->data = new T[this->t_size];

        memset(this->data, 0, this->t_size * sizeof(T));
    }

    int64_t front() {
        return data[this->t_front];
    }

    int64_t back() {
        return data[this->t_back];
    }

    int64_t size() {
        return this->empty() ? 0 : this->t_back - this->t_front + 1;
    }

    bool empty() {
        return this->t_front == -1 && this->t_back == -1;
    }

    bool full() {
        return this->t_back == (int64_t)this->t_size - 1;
    }

    void enqueue(T val) {
        try {
            if (this->full()) throw true;

            if (this->empty()) {
                this->t_front = this->t_back = 0;
                data[this->t_back] = val;
            } else {
                data[++(this->t_back)] = val;
            }

        } catch (bool err) {
            cout << "\nQueue Overflow.\n";
            return;
        }
    }

    T dequeue() {
        try {
            if (this->empty()) throw true;

            T temp = this->data[this->t_front];

            if (this->t_front == this->t_back) {
                this->t_back = this->t_front = -1;
            } else {
                ++this->t_front;
            }

            return temp;
        } catch (bool err) {
            cout << "\nQueue Underflow.\n";
            return -1;
        }
    }

    void reverseUsingStack() {
        stack<T> s;

        while (!this->empty())
            s.push(this->dequeue());

        while (!s.empty()) {
            this->enqueue(s.top());
            s.pop();
        }

        return;
    }

    void reverseUsingRecursion() {
        if (this->empty()) return;

        T temp = this->dequeue();

        reverseUsingRecursion();

        this->enqueue(temp);
    }

    ~Queue() {
        delete[] data;
    }
};
