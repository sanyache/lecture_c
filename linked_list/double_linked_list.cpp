#include <iostream>
#include<string>
using namespace std;
typedef int Item;
 
struct Node {
    Item item;
    Node* next;
    Node* prev;
    Node(Item x){
        item = x;
        next = nullptr;
        prev = nullptr;
    }
};

typedef Node* link;

class LinkedList {
private:
    Node* head; 
    Node* tail; 
public:
    LinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void push_back(int value) {
        Node* newNode = new Node(value);    
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        tail->prev = newNode;
    }
    
    void push_front(int value) {
        insert_after(head, value);
        
    }
    
    Item pop_back() {
        if (this->is_empty()) {
            throw invalid_argument("list is empty");
        }
        int result = tail->prev->item;
        erase(tail->prev);
        
        return result;
    }
    
    Item pop_front() {
        if (this->is_empty()) {
            throw invalid_argument("list is empty");
        }
        int result = head->next->item;
        erase(head->next);
                  
        return result;
    }
    
    void insert_after(Node* pos, Item item) {
        
        Node* newNode = new Node(item);
        newNode->next = pos->next;
        newNode->prev = pos;
        pos->next->prev = newNode;
        pos->next = newNode;
        
    }
    Node* find(Item item){

        for(auto it=this->begin(); it!=this->end(); it=it->next ){
            if(it->item == item){
                return it;
            }
        }
        return nullptr;
    }
    void erase(Node* node) {
        if (this->is_empty()) {
            throw invalid_argument("list is empty");
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        delete node;
    }
    
    Node*  begin() const {
        return head->next;
    }
    
    Node* end() const {
        return tail;
    }
    
    bool is_empty() const {
        return head->next == tail;
    }

    void print_list() const{
        for(auto it=this->begin(); it!=this->end(); it=it->next ){
            cout<<it->item<<' ';
        }
        cout<<'\n';
    }
    
    ~LinkedList() {
        while (!is_empty()) {
            Item item = pop_back();
            cout<<item<<'\n';
        }
        delete tail;
        delete head;
    }
};    

int main() {
    LinkedList list = LinkedList();
    //list.pop_back();
    list.push_front(20);
    list.push_back(30);
    list.push_back(40);
    list.print_list();
    cout<<list.pop_back()<<'\n';
    list.pop_front();
    link pos = list.find(30);
    list.insert_after(pos, 50);
    list.insert_after(pos, 35);
    // for (int i = 0; i < 10; ++i) {
    //     list.push_back(i);
    // }
    // list.pop_front();
    // list.push_front(5);
    list.print_list();
    return 0;
}