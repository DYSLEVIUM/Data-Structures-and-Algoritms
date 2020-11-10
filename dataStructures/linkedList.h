template <typename T>
class List {
   private:
    ListNode<T>* head;
    ListNode<T>* temp;

   public:
    List() : head(nullptr), temp(nullptr) {}

    bool empty() {
        return this->head == nullptr;
    }

    T front() {
        try {
            if (this->empty()) throw true;
            return this->head->data;
        } catch (bool err) {
            cout << "\nList is empty.\n";
            return T(-1);
        }
    }

    T back() {
        try {
            if (this->empty()) throw true;
            if (this->head->next == nullptr) return this->head->data;

            this->temp = this->head;

            while (this->temp->next != nullptr) {
                this->temp = this->temp->next;
            }

            return this->temp->data;
        } catch (bool err) {
            cout << "\nList is empty.\n";
            return T(-1);
        }
    }

    void push_front(T da) {
        ListNode<T>* newNode = new ListNode<T>(da);

        newNode->next = this->head;
        this->head = newNode;
    }

    void push_back(T da) {
        ListNode<T>* newNode = new ListNode<T>(da);  //  creating the node
        newNode->next = nullptr;                     //  pushing it to the last of the list so next is nullptr

        if (this->empty()) {  //  we can't access pointer if it is nullptr
            this->head = newNode;
        } else {
            this->temp = this->head;
            while (this->temp->next != nullptr) {
                this->temp = this->temp->next;
            }

            this->temp->next = newNode;
        }
    }

    void pop_front() {
        try {
            if (this->empty()) throw true;

            this->temp = this->head;
            this->head = this->head->next;

            this->temp = nullptr;
            delete this->temp;
        } catch (bool err) {
            cout << "List is empty.\n";
        }
    }

    void pop_back() {
        try {
            if (this->empty()) throw true;

            ListNode<T>* currNode = this->head;

            while (currNode->next->next != nullptr) {
                currNode = currNode->next;
            }

            currNode->next = nullptr;
            delete currNode->next;
        } catch (bool err) {
            cout << "\nList is empty.\n";
        }
    }

    void insert() {}
    void erase() {}
    void reverse() {}

    ~List() {
        if (!this->empty()) {
            ListNode<T>* currNode = this->head;
            ListNode<T>* prevNode;

            while (currNode != nullptr) {
                prevNode = currNode;
                currNode = currNode->next;
            }

            prevNode = nullptr;
            currNode = nullptr;

            delete currNode;
            delete prevNode;
        }

        delete this->head;
        delete this->temp;
    }
};
