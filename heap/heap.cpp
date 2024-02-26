#include<iostream>
#include<vector>

using namespace std;

typedef int Item;

struct Heap{

    vector <Item> H;
    void heap_push(Item item){
        H.push_back(item);
        size_t indx = H.size()-1;
        size_t parent = (indx-1)/2;
        while(indx != 0 and H[indx] > H[parent]){
            swap(H[indx], H[parent]);
            indx = parent;
            parent = (indx-1)/2;
        }
    }
    Item heap_pop(){
        Item pop = H[0];
        swap(H[0], H[H.size()-1]);
        H.pop_back();
        size_t indx = 0;
        size_t left = 2*indx + 1;
        size_t right = 2*indx+ 2;
        while(left < H.size() and H[left]> H[indx] or
              right < H.size() and H[right] > H[indx] ){
            if(right>=H.size() or H[left] > H[right]){
                swap(H[indx], H[left]);
                indx = left;
            } else {
                swap(H[indx], H[right]);
                indx = right;
            }
            left = 2*indx+1;
            right = 2*indx+2;
        }

        return pop;
    }
    bool heap_is_empty(){
        return H.empty();
    }
};

int main(){
    Item item;
    Heap heap;
    for(size_t i=0; i<10; i++){
        cin>>item;
        heap.heap_push(item);
    }
    while(!heap.heap_is_empty()){
        cout<<heap.heap_pop()<<' ';
    }
    return 0;
}
