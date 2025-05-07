#include<iostream>

using namespace std;
typedef int Item;
struct  Node
{
    Item item;
    Node* next;
    Node(Item x, Node* t){
        item = x;
        next = t;
    } 
};
typedef Node* link;

int main(){
link first_node = new Node(100, nullptr);
cout<<"first item="<<first_node->item<<endl;
cout<<"first next="<<first_node->next<<endl;
link second_node = new Node(200, nullptr);
first_node->next = second_node;
cout<<"second="<<first_node->next->item;

} 