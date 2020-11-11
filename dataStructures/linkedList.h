template <typename T>
class List {
   private:
    ListNode<T>* t_head;
    uint16_t t_size;

   public:
    List() : t_head(nullptr), t_size(0) {}

    bool empty() {
        return this->t_size == 0;
    }

    T front() {
        try {
            if (this->empty()) throw true;
            return this->t_head->data;
        } catch (bool err) {
            cout << "\nList is empty.\n";
            return T(-1);
        }
    }

    T back() {
        try {
            if (this->empty()) throw true;

            ListNode<T>* currNode = this->t_head;

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

        newNode->next = this->t_head;
        this->t_head = newNode;
        ++this->t_size;
    }

    void push_back(T da) {
        ListNode<T>* newNode = new ListNode<T>(da);  //  creating the node
        newNode->next = nullptr;                     //  pushing it to the last of the list so next is nullptr

        if (this->empty()) {  //  we can't access pointer if it is nullptr
            this->t_head = newNode;
        } else {
            ListNode<T>* currNode = this->t_head;

            while (currNode->next != nullptr) {
                currNode = currNode->next;
            }

            currNode->next = newNode;

            currNode = nullptr;
        }

        ++this->t_size;
    }

    void pop_front() {
        try {
            if (this->empty()) throw true;

            ListNode<T>* temp = this->t_head;
            this->t_head = this->t_head->next;

            delete temp;
            temp = nullptr;
            --this->t_size;
        } catch (bool err) {
            cout << "List is empty.\n";
        }
    }

    void pop_back() {
        try {
            if (this->empty()) throw true;

            ListNode<T>* currNode = this->t_head;

            while (currNode->next->next != nullptr) {
                currNode = currNode->next;
            }

            delete currNode->next;  //  using secong last node to delete ; because deleteing from last node deletes the address of the node also and the second last node is left dangling
            currNode->next = nullptr;
            --this->t_size;
        } catch (bool err) {
            cout << "\nList is empty.\n";
        }
    }

    // void insert(int pos, T da) {
    //     ListNode<T>* newNode = new ListNode<T>(da);

    //     this->temp = this->t_head;

    //     while (pos--) {
    //         this->temp = this->temp->next;
    //     }

    //     newNode->next = this->temp->next;

    //     this->temp->next = newNode;
    // }
    // void erase() {}
    // void reverse() {}

    // ListNode<T>* getHead() {
    //     return this->t_head;
    // }

    void display() {
        ListNode<T>* currNode = this->t_head;
        while (currNode != nullptr) {
            cout << currNode->data << " -> ";
            currNode = currNode->next;
        }
        cout << "nullptr\n";
    }

    ListNode<T>* head() {
        return this->t_head;
    }

    uint16_t size() {
        return this->t_size;
    }

    ~List() {
        if (!this->empty()) {
            while (this->t_head != nullptr) {
                ListNode<T>* currNode = this->t_head;
                this->t_head = this->t_head->next;

                delete currNode;
                currNode = nullptr;
            }
        }
    }
};
