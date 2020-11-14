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

    void push_front(T da) {
        DListNode<T>* newNode = new DListNode<T>(da);

        newNode->next = this->t_head;
        this->t_head = newNode;
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
