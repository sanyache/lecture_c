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
        link find_pos = nullptr;
        for(auto it=this->begin(); it!=this->end(); it = it->next){
            if(it->item == item) {
                find_pos = it;
                break;
            }
        }
        return find_pos;
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
    void erase(Item item){
        if(not this->is_empty()){
            bool find = false;
            if(item == head->item){
                link tmp = head;
                head = tmp->next;
                delete tmp;
                find = true;
            } else {
                link prev = head;
                while(prev->next != nullptr){
                    if(prev->next->item == item){
                        link tmp = prev->next;
                        prev->next = tmp->next;
                        delete tmp;
                        break;
                        find = true;
                    } 
                    prev = prev->next;
                }    
            }
            if (find)
                capacity--;
            else
                cout<<"element not found"<<endl;    
        } else{ 
            cout<<"The list is empty"<<endl;
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
        while (!is_empty()) {
            cout<<head->item<<'\n';
            erase(head->item);
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