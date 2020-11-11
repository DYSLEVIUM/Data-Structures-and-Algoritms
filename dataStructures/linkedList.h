template <typename T>
class List {
   private:
    ListNode<T>* head;

   public:
    List() : head(nullptr) {}

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

            ListNode<T>* currNode = this->head;

            while (currNode->next != nullptr) {  //  traversing through the list
                currNode = currNode->next;
            }

            T temp = currNode->data;  //  storing value to return it

            delete currNode;
            currNode = nullptr;

            return temp;
        } catch (bool err) {
            cout << "\nList is empty.\n";
            return T(-1);
        }
    }

    void push_front(T da) {
        ListNode<T>* newNode = new ListNode<T>(da);  //  making a new node

        newNode->next = this->head;
        this->head = newNode;
    }

    void push_back(T da) {
        ListNode<T>* newNode = new ListNode<T>(da);  //  creating the node
        newNode->next = nullptr;                     //  pushing it to the last of the list so next is nullptr

        if (this->empty()) {  //  we can't access pointer if it is nullptr
            this->head = newNode;
        } else {
            ListNode<T>* currNode = this->head;

            while (currNode->next != nullptr) {
                currNode = currNode->next;
            }

            currNode->next = newNode;

            currNode = nullptr;
        }
    }

    void pop_front() {
        try {
            if (this->empty()) throw true;

            ListNode<T>* temp = this->head;
            this->head = this->head->next;

            delete temp;
            temp = nullptr;
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

            delete currNode->next;
            currNode->next = nullptr;
        } catch (bool err) {
            cout << "\nList is empty.\n";
        }
    }

    // void insert(int pos, T da) {
    //     ListNode<T>* newNode = new ListNode<T>(da);

    //     this->temp = this->head;

    //     while (pos--) {
    //         this->temp = this->temp->next;
    //     }

    //     newNode->next = this->temp->next;

    //     this->temp->next = newNode;
    // }
    // void erase() {}
    // void reverse() {}

    // ListNode<T>* getHead() {
    //     return this->head;
    // }

    void display() {
        ListNode<T>* currNode = this->head;
        while (currNode != nullptr) {
            cout << currNode->data << " -> ";
            currNode = currNode->next;
        }
        cout << "nullptr\n";
    }

    ~List() {
        if (!this->empty()) {
            while (this->head != nullptr) {
                ListNode<T>* currNode = this->head;
                this->head = this->head->next;

                delete currNode;
                currNode = nullptr;
            }
        }
    }
};
