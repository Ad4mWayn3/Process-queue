template <class T>
struct DLinkList {
    T& value;
    DLinkList<T>* prev;
    DLinkList<T>* next;
    
    ~DLinkList<T>() {
        if (prev) prev->next = nullptr;
        if (next) next->prev = nullptr;
    }
};

template <class T>
struct Queue {
    DLinkList<T>* head;
    DLinkList<T>* tail;
    
    static Queue<T> empty() {
        Queue<T> out;
        out.head = nullptr;
        out.tail = nullptr;
        return out;
    }
    
    static Queue<T> build(T& value) {
        Queue<T> out;
        out.head = new DLinkList<T>{value, nullptr, nullptr};
        out.tail = out.head;
        return out;
    }
    
    Queue<T>& push(T& value) {
        if (!head) {
            *this = Queue<T>::build(value);
            return *this;
        }
        
        if (head && (head == tail)) {
            head->next = new DLinkList<T>{value, head, nullptr};
            tail = head->next;
            return *this;
        }
        
        tail->next = new DLinkList<T>{value, tail, nullptr};
        tail = tail->next;
        return *this;
    }
    
    T& pop() {
        T& out = head->value;
        delete head;
        return out;
    }
};
