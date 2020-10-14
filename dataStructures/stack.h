template <typename T>
class Stack {
   private:
    int64_t t_top;
    uint64_t t_size;
    T* data;

   public:
    Stack() : t_top(-1), t_size(5), data(new T[this->t_size]) {  //  default constructor with data size 5
        memset(this->data, 0, this->t_size * sizeof(T));
    }

    Stack(uint64_t size) {
        this->t_top = -1;
        this->t_size = size;

        this->data = new T[this->t_size];

        memset(this->data, 0, this->t_size * sizeof(T));
    }

    T top() {
        return this->data[this->t_top];
    }

    uint64_t size() {
        return this->t_top + 1;
    }

    bool empty() {
        return this->t_top == -1;
    }

    bool full() {
        return this->t_top == (int64_t)this->t_size - 1;
    }

    void push(T val) {
        try {
            if (this->full()) throw true;

            ++this->t_top;
            this->data[this->t_top] = val;
        } catch (bool err) {
            cout << "\nStack Overflow.\n";
            return;
        }
    }

    T pop() {
        try {
            if (this->empty()) throw true;

            T popVal = this->data[this->t_top];

            --this->t_top;
            return popVal;
        } catch (bool err) {
            cout << "\nStack Underflow.\n";
            return (T)-1;
        }
    }

    T peek(uint64_t pos) {
        try {
            if ((int64_t)pos >= this->t_top) throw true;

            return this->data[pos];
        } catch (bool err) {
            cout << "\nOut of bounds.\n";
            return (T)-1;
        }
    }

    ~Stack() {
        delete[] data;
    }
};