#include<iostream>

using namespace std;

void bubble_sort(int A[], int n){
    bool is_swapped;
    for(int i=0; i<n-1; i++){
        is_swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                is_swapped = true;
            }
        }
        if(!is_swapped){
            break;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    bubble_sort(A, n);
    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}