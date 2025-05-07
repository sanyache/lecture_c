#include<iostream>

using namespace std;

struct Node
    {
        int item;
        Node* next;
        Node(int x, Node* t=nullptr){
            item = x;
            next = t;
        }
    };

typedef Node* link;    

int main(){

    link first_node = new Node(1);
    cout<<first_node->item<<'\n';
    link second_node = new Node(2);
    first_node->next = second_node;
    cout<<second_node->item<<' '<<first_node->next->item<<'\n';
    link third_node = new Node(3);
    second_node->next = third_node;
    cout<<first_node->next->next->item<<'\n';
    link t = first_node->next;
    delete t;
    first_node->next = first_node->next->next;
    cout<<first_node->next->item<<'\n';
    delete third_node;
    delete first_node;

    return 0;
}