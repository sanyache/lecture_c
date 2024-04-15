#include<iostream>
/* Задача Іосіфа Флавія. N - чоловіків вирішили обрати собі атамана. Для цього
вони стали в коло і видаляють кожного target змикаючи при цьому коло. Хто
залишиться останнім? */
using namespace std;

struct Node
{
    int item;
    Node* next;
    Node(int x, Node* t){
        item = x;
        next = t;
    }
};
typedef Node* link;
int main(){
    int n, target;
    cout<<"Enter the number of guys: "<<endl;
    cin>>n;
    cout<<"Enter the target number: "<<endl;
    cin>>target;
    link first = new Node(1, nullptr);
    first->next = first;
    link prev = first;
    for(int i=2; i<=n; i++){
        link new_node = new Node(i, first);
        prev->next = new_node;
        prev = new_node;
    }
    while (prev!=prev->next)
    {
        for(int i=1; i<target; i++){
            prev = prev->next;
        }
        cout<<"the leaving number"<<(prev->next)->item<<'\n';
        link tmp = prev->next;
        prev->next = tmp->next;
        delete tmp;
    }
    
    cout<<"the remaining number="<<prev->item<<endl;
    delete (prev);
    return 0;
}