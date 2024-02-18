#include<iostream>

using namespace std;

void print_arr(int A[], int n){
    for(int i=0; i<n; i++){

        cout<<A[i]<<' ';
    }
    cout<<'\n';
}
void reverse_array(int A[], int start, int stop){
    cout<<start<<"  "<<stop<<'\n';
    for(int i=start; i<(stop+start)/2; i++){
        int tmp = A[i];
        A[i] = A[stop-1-i+start];
        A[stop-1-i+start] = tmp;
    }
    print_arr(A, 7);
}

int main(){

    int A[] = {1, 2, 3, 4, 5, 6, 7};

    int d = 2;
    int n = sizeof(A)/sizeof(A[0]);

    reverse_array(A, 0, d);
    print_arr(A, n);
    reverse_array(A, d, n);
    print_arr(A, n);
    reverse_array(A, 0, n);
    print_arr(A, n);


    return 0;
}
