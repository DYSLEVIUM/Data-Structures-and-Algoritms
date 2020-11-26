template <typename T>
class DList;

template <typename T>
class DListNode {
   private:
    friend class DList<T>;  //  making dList class to access private members of DListNode
    T data;
    DListNode* next;
    DListNode* prev;

   public:
    DListNode(T da) : data(da), next(nullptr), prev(nullptr) {
    }

    getData() {
        return this->data;
    }

    virtual ~DListNode() {
        next = nullptr;
        prev = nullptr;

        delete next;
        delete prev;
    }
};

template <typename T>
class DList {
   private:
    DListNode<T>* t_head;
    uint16_t t_size;

   public:
    DList() : t_head(nullptr), t_size(0) {}

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

            DListNode<T>* currNode = this->t_head;
            while (currNode->next != nullptr) {
                currNode = currNode->next;
            }

            return currNode->data;

        } catch (bool err) {
            cout << "\nList is empty.\n";
            return T(-1);
        }
    }

    void push_front(T da) {
        DListNode<T>* newNode = new DListNode<T>(da);

        newNode->next = this->t_head;
        this->t_head = newNode;
        ++this->t_size;
    }

    void push_back(T da) {
        DListNode<T>* newNode = new DListNode<T>(da);

        DListNode<T>* currNode = this->t_head;

        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }

        currNode->next = newNode;
        newNode->prev = currNode;
        ++this->t_size;
    }

    void pop_front() {
        try {
            if (this->empty()) throw true;

            DListNode<T>* temp = this->t_head;

            this->t_head = this->t_head->next;
            this->t_head->prev = nullptr;

            delete temp;
            temp = nullptr;
            --this->t_size;
        } catch (bool err) {
            cout << "\nList is empty.\n";
        }
    }

    void pop_back() {
        try {
            if (this->empty()) throw true;

            DListNode<T>* secondLast = this->t_head;

            while (secondLast->next->next != nullptr) {
                secondLast = secondLast->next;
            }

            secondLast->next = nullptr;  // secondLast becomes the last node

            DListNode<T>* temp = secondLast->next;

            delete temp;
            temp = nullptr;

            --this->t_size;
        } catch (bool err) {
            cout << "\nList is empty.\n";
        }
    }

    void insert(int pos, T da) {
        try {
            if (pos < 0 || pos > this->t_size) throw true;

            if (pos == 0) {
                this->push_front(da);
            } else {
                DListNode<T>* newNode = new DListNode<T>(da);
                DListNode<T>* temp = this->t_head;

                while (--pos > 0) {  //  --pos because we are traversing to the node just before the insertion place
                    temp = temp->next;
                }

                newNode->prev = temp;

                if (temp->next == nullptr) {  //  edge case if the node is at last
                    newNode->next = nullptr;
                } else {
                    newNode->next = temp->next;
                    temp->next->prev = newNode;
                }

                temp->next = newNode;
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
                this->pop_front();
            } else if (pos == this->t_size - 1) {
                this->pop_back();
            } else {
                DListNode<T>* penUltimate = this->t_head;  //  going to the node just before the deletion node
                --pos;                                     //  --pos so that we reach the node just before the to be deleted node
                while (pos-- > 0) {                        //  pos-- because we are traversing to the node to be deleted
                    penUltimate = penUltimate->next;
                }
                DListNode<T>* nodeToDelete = penUltimate->next;

                if (penUltimate->next->next == nullptr) {
                    penUltimate->next = nullptr;
                } else {
                    penUltimate->next = nodeToDelete->next;
                    nodeToDelete->next->prev = penUltimate;
                }

                delete nodeToDelete;
                nodeToDelete = nullptr;
            }
            --this->t_size;
        } catch (bool err) {
            cout << "\nIndex is out of range.\n";
        }
    }

    void reverse() {
    }

    void print() {
        DListNode<T>* currNode = this->t_head;  //  making newNode to traverse the dList

        cout << "nullptr <-> ";
        while (currNode != nullptr) {
            cout << currNode->data << " <-> ";
            currNode = currNode->next;
        }
        cout << "nullptr\n";
    }

    DListNode<T>* head() {
        return this->t_head;
    }

    uint16_t size() {
        return this->t_size;
    }

    ~DList() {
    }
};
