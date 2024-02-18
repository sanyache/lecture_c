#include<iostream>

using namespace std;

void print_array(int A[], int n){
    for(int i=0; i<n; i++){

        cout<<A[i]<<' ';
    }
    cout<<'\n';
}

void arr_push_back(int A[], int &top, int el){

    A[top] = el;
    top ++;
}

int arr_pop_back(int A[], int &top){

    top --;
    int el = A[top];
    return el;
}

void arr_push_front(int A[], int &top, int el){

    for(int i = top; i > 0; i--){
        A[i] = A[i-1];
    }
    top ++;
    A[0] = el;
}

int arr_pop_front(int A[], int &top){
    int el = A[0];
    for(int i=0; i<top-1; i++){
        A[i] = A[i+1];
    }
    top --;
    return el;
}

int main(){

    int A[100];
    int top = 0;
    for(int i=1; i<=7; i++){
        arr_push_back(A, top, i);
    }
    arr_push_back(A, top, 8);
    print_array(A,top);
    cout<<'\n'<<arr_pop_back(A, top)<<'\n';
    print_array(A, top);
    arr_push_front(A, top, 8);
    print_array(A, top);
    arr_pop_front(A, top);
    print_array(A, top);
    return 0;
}
