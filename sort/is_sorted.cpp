#include<iostream>

using namespace std;

bool is_sorted(int A[], int n){
    for(int i=0; i<n-1; i++){
        if(A[i] > A[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    if(is_sorted(A, n)){
        cout<<"The array is sorted";
    }else{
        cout<<"The array is not sorted";
    }
}