#include<iostream>

using namespace std;    

void insert_sort(int A[], int n){
    for(int i=1; i<n; i++){
        int key = A[i];
        int j = i;
        while (j>0 && key < A[j-1])
        {
            A[j] = A[j-1];
            j--;
        }
        A[j] = key; 
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
    insert_sort(A, n);
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}