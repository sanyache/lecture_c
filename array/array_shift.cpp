#include<iostream>

using namespace std;

void print_arr(int A[], int n){
    for(int i=0; i<n; i++){

        cout<<A[i]<<' ';
    }
    cout<<'\n';
}

void shift_left(int A[], int n){

    int tmp = A[0];
    for(int i=0; i<n-1; i++)
        A[i] = A[i+1];
    A[n-1] = tmp;
}

void shift_right(int A[], int n){

    int tmp = A[n-1];
    for(int i=n-2; i>=0; i--){
        A[i+1] = A[i];
    }
    A[0] = tmp;
}

int main(){

    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A)/sizeof(A[0]);
    shift_left(A, n);
    print_arr(A, n);
    shift_right(A, n);
    print_arr(A, n);
    return 0;
}
