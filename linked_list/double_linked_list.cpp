#include <iostream>
#include<string>
using namespace std;
typedef int Item;
struct Node {
    Item item;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(Item x){
        item = x;
    }
};

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = new Node(0);
public:
    LinkedList() {}
    
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = tail;
            tail->prev = head;
        } else {
            tail->prev->next = newNode;
            newNode->next = tail;
            newNode->prev = tail->prev;
            tail->prev = newNode;
        }
    }
    
    void push_front(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = tail;
            tail->prev = head;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    Item pop_back() {
        if (head == nullptr) {
            throw invalid_argument("list is empty");
        }
        int result = tail->prev->item;
        if (tail->prev == head){
            delete tail->prev;
            head = nullptr;
            return result;
        }
        auto prev = tail->prev->prev;
        delete tail->prev;
        tail->prev = prev;
        prev->next = tail;
        return result;
    }
    
    Item pop_front() {
        if (head == nullptr) {
            invalid_argument("list is empty");
        }
        int result = head->item;
        if(head->next == tail){
            delete head;
            head = nullptr;        
        } else{
            auto tmp = head->next;
            delete head;
            head = tmp;
        }    
        return result;
    }
    
    void insert(Node* pos, Item item) {
        if (pos->next == tail) {
            push_back(item);
            return;
        }
        Node* newNode = new Node(item);
        newNode->next = pos->next;
        newNode->prev = pos;
        pos->next->prev = newNode;
        pos->next = newNode;
    }
    
    void erase(Node* node) {
        if (node == head) {
            pop_front();
            return;
        }
        if (node->next == tail) {
            pop_back();
            return;
        }
        auto prev = node->prev;
        auto next = node->next;
        prev->next = next;
        next->prev = prev;
        delete node;
    }
    
    Node*  begin() const {
        return head;
    }
    
    Node* end() const {
        return tail;
    }
    
    bool is_empty() const {
        return head == nullptr;
    }

    void print_list() const{
        for(auto it=this->begin(); it!=this->end(); it=it->next ){
            cout<<it->item<<' ';
        }
    }
    
    ~LinkedList() {
        while (!is_empty()) {
            Item item = pop_back();
            cout<<item<<'\n';
        }
        delete tail;
    }
};    

int main() {
    LinkedList list = LinkedList();
    //list.pop_back();
    list.push_front(20);
    list.pop_front();
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    list.pop_front();
    list.push_front(5);
    list.print_list();
    return 0;
}