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
public:
    LinkedList(){};
    link insert(link pos, Item item){
        link new_node = new Node(item, nullptr);
        if(this->is_empty()){
            head = new_node;
        } else{
            pos->next = new_node;
        }
        return new_node;
    }
    link find(Item item){
        link find_pos = nullptr;
        for(auto it=this->front(); it!=this->back(); it = it->next){
            if(it->item == item) {
                find_pos = it;
                break;
            }
        }
        return find_pos;
    }
    link front() const {
        return head;
    }
    
    link back() const {
        return nullptr;
    }
    
    bool is_empty() const {
        return head == nullptr;
    }
    void erase(Item item){
        if(item == head->item){
            link tmp = head;
            head = tmp->next;
            delete tmp;
        }
        link prev = head;
        while(prev->next != nullptr){
            if(prev->next->item == item){
                link tmp = prev->next;
                prev->next = tmp->next;
                delete tmp;
                break;
            } 
            prev = prev->next;
        }
    }
    void print_list(){
        for(auto it=this->front(); it!=this->back(); it = it->next){
            cout<<it->item<<' ';
        }
        cout<<'\n';  
    }
};

int main(){
    LinkedList list = LinkedList();
    link position = nullptr;
    for (int i = 0; i < 10; ++i) {
        position = list.insert(position, i);
    }
    list.print_list();
    link pos = list.find(5);
    cout<<'\n'<<pos->item<<endl;
    list.erase(9);
    list.print_list();
    return 0;
}