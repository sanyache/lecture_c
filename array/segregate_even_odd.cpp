#include<iostream>

using namespace std;

void print_arr(int A[], int n){
    for(int i=0; i<n; i++){

        cout<<A[i]<<' ';
    }
    cout<<'\n';
}


int main()
{
    int A[] = {7,2,9,4,6,1,3,8,12};
    int n = sizeof(A)/sizeof(A[0]);
    print_arr(A, n);
    int even_ind = 0;
    for(int i=0; i<n; i++){
        if(A[i]%2 == 0){
            swap(A[i], A[even_ind]);
            even_ind ++;
        }
        cout<<"even_ind="<<even_ind<<'\t';
        print_arr(A, n);

    }
    print_arr(A, n);
}

