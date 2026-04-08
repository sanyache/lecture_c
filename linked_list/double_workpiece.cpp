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
       





    }
    
    void push_front(int value) {
        




        
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
        




        
    }
};    

int main() {
    LinkedList list = LinkedList();
    list.push_front(20);
    list.push_back(30);
    list.push_back(40);
    list.print_list();
    cout<<list.pop_back()<<'\n';
    list.pop_front();
    link pos = list.find(30);
    list.insert_after(pos, 50);
    list.insert_after(pos, 35);
    list.print_list();
    return 0;
}