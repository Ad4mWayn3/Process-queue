#include <thread>
#include <vector>

struct Process {
    const char* name;
    unsigned priority;
};

struct Node {
    Node* prev = nullptr;
    Process* curr;
    Node* next = nullptr;
};

struct Queue {
    Node _begin;
    Process* _end;
    
    Queue& push(Process process){
        _begin.next = _begin.curr;
        _begin.next.
        _begin.curr = new Process{process};
        return *this;
    }
    
    Process* pop(){
        Process* out = _end;
        
    }
};