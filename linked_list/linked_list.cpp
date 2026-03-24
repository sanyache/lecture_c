#include<iostream>

using namespace std;
typedef int Item;
struct Node
{
    Item item;
    Node* next;
    Node(Item x, Node* t){
        item = x;
        next = t;
    }
};
typedef Node* link;
class  LinkedList
{
private:
    link head = nullptr;
    int capacity = 0;
public:
    LinkedList(){};
    link insert(link pos, Item item){
        link new_node = new Node(item, nullptr);
        if(this->is_empty()){
            head = new_node;
        } else{
            new_node->next = pos ->next;
            pos->next = new_node;
        }
        capacity ++;
        return new_node;
    }
    link find(Item item){
        for(auto it=this->begin(); it!=this->end(); it = it->next){
            if(it->item == item) {
                return it;
            }
        }
        return nullptr;
    }
    link begin() const {
        return head;
    }
    
    link end() const {
        return nullptr;
    }
    
    bool is_empty() const {
        return head == nullptr;
    }
    void erase(Item x){
        if(not this->is_empty()){
            bool is_find = false;
            if(x == head->item){
                link tmp = head;
                head = tmp->next;
                delete tmp;
                is_find = true;
            } else {
              for(auto it= begin(); it->next != end(); it = it->next){
                if(it->next->item == x){
                    Node* tmp = it->next;
                    it->next = it->next->next;
                    is_find = true;
                    break;
                }  
              }   
            }
            if (!is_find){    
                cout<<"Element not found"<<endl;
            }  else {
                capacity --;
            }  
        } else {
            cout<<"This list is empty"<<'\n';
        }    
    }
    void print_list(){
        for(auto it=this->begin(); it!=this->end(); it = it->next){
            cout<<it->item<<' ';
        }
        cout<<'\n';  
    }
    int size(){
        return capacity;
    }
    ~LinkedList() {
        Node* it = head;
        while ( it != nullptr) {
            Node* tmp = it;
            it = it->next;
            delete tmp;
        }
    }
};

int main(){
    LinkedList list = LinkedList();
    link position = nullptr;
    for (int i = 0; i < 10; ++i) {
        position = list.insert(position, i);
    }
    cout<<"list's size="<<list.size()<<endl;
    list.print_list();
    link pos = list.find(5);
    list.insert(pos, 10);
    cout<<"list's size="<<list.size()<<endl;
    cout<<'\n'<<pos->item<<endl;
    list.erase(15);
    cout<<"list's size="<<list.size()<<endl;
    list.erase(9);
    list.print_list();
    return 0;
}