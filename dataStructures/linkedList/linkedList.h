template <typename T>
class List;

template <typename T>
class ListNode {
   private:
    friend class List<T>;  //  making list class to access private members of ListNode
    T data;
    ListNode* next;

   public:
    ListNode(T da) : data(da), next(nullptr) {}

    T getData() {
        return this->data;
    }

    virtual ~ListNode() {
        next = nullptr;
        delete next;
    }
};

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

            return currNode->data;
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

    void insert(int pos, T da) {
        try {
            if (pos < 0 || pos > this->t_size) throw true;
            ListNode<T>* newNode = new ListNode<T>(da);

            if (pos == 0) {
                newNode->next = this->t_head;
                this->t_head = newNode;
            } else {
                ListNode<T>* temp = this->t_head;
                while (--pos > 0) {  //  --pos because we are traversing to the node just before the insertion place
                    temp = temp->next;
                }

                newNode->next = temp->next;

                temp->next = newNode;

                temp = nullptr;
            }
            ++this->t_size;
        } catch (bool err) {
            cout << "\nIndex is out of range.\n";
        }
    }
   
    void erase(int pos) {
        try {
            if (pos < 0 || pos > this->t_size - 1) throw true;

            if (pos == 0) {
                ListNode<T>* temp = this->t_head;  //  saving this node to delete it
                this->t_head = this->t_head->next;

                delete temp;
                temp = nullptr;
            } else if (pos == this->t_size - 1) {
                this->pop_back();
            } else {
                ListNode<T>* currNode = this->t_head;
                ListNode<T>* prevNode;

                while (pos-- > 0) {  //  pos-- because we are traversing to the node to be deleted
                    prevNode = currNode;
                    currNode = currNode->next;
                }

                prevNode->next = currNode->next;
                delete currNode;
                currNode = nullptr;
            }

            --this->t_size;
        } catch (bool err) {
            cout << "\nIndex is out of range.\n";
        }
    }
    void reverse() {
        ListNode<T>*currNode = this->t_head, *prevNode = nullptr, *nextNode = nullptr;

        while (currNode != nullptr) {
            nextNode = currNode->next;  //  saving next node to use it to traverse
            currNode->next = prevNode;  //  changing pointer to point to the previous node
            prevNode = currNode;        //  changing previous for next iteration
            currNode = nextNode;        //  changing current node to the next node for next iteration
        }

        this->t_head = prevNode;
    }

    void reverseUsingRecursion(ListNode<T>* currNode) {
        if (currNode->next == nullptr) {  //  base case when only one node is left that will become head
            this->t_head = currNode;
            return;
        }

        this->reverseUsingRecursion(currNode->next);  //  reversing the remaining list

        //  suppose we have two node (one currentNode and the other is full list considered as only one node), so we just have to swap the nodes' links
        ListNode<T>* prevNode = currNode->next;
        prevNode->next = currNode;
        currNode->next = nullptr;
    }

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
