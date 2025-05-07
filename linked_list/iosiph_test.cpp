#include<iostream>

using namespace std;
typedef int Item;

struct  Node
{
    Item item;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(Item x){
        item = x;
    }
};
typedef Node* link;
class LinkedList
{
private:
    link head = nullptr;
    link tail = new Node(0);
    int counter = 0;
public: 
    LinkedList(){};
    void push_front(Item item){
        Node* newNode = new Node(item);
        if(head == nullptr){
            head = newNode;
            head ->next = tail;
            tail->prev = head;
        } else {
            newNode ->next = head;
            head -> prev = newNode;
            head = newNode;        
        }
    }
    Item pop_front(){
        Item result;
        if(head == nullptr){
            invalid_argument("list is empty");
        } else {
            result = head->item;
            if(head->next == tail ){
                delete head;
                head = nullptr;
            } else {
                Node* tmp = head->next;
                delete head;
                head = tmp;
            }
        }
        return result;
    }
    bool is_empty() const{
        return head == nullptr;
    }
    link begin() const{
        return head;
    }
    link end() const {
        return tail; 
    }
    void print_list() const{
        for(auto it=this->begin(); it!=this->end(); it=it->next){
            cout<<it->item<<' ';
        }
    }
    int size(){
        return counter;
    }
    ~ LinkedList(){
        while (!is_empty())
        {
            pop_front();
        }
        delete tail;
        
    }
    
};

int main(){
    LinkedList list = LinkedList();
    list.push_front(20);
    for(int i=0; i<10; i++){
        list.push_front(i);
    }
    Item el = list.pop_front();
    cout<<el<<'\n';
    list.print_list();
}