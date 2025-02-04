#include<iostream>

using namespace std;

void selection(int A[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[min]){
                min = j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
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
    selection(A, n);
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}