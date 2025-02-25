#include<iostream>

using namespace std;

void merge(int A[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m; 
    int L[n1], R[n2];
    for(int i=0; i<n1; i++){
        L[i] = A[l+i];
    }
    for(int i=0; i<n2; i++){
        R[i] = A[m+1+i];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if (L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }

}

void merge_sort(int A[], int l, int r){
    if (l>=r){
        return;
    }
    int m = l + (r-l)/2;
    merge_sort(A, l, m);
    merge_sort(A, m+1, r);
    merge(A, l, m, r);
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    merge_sort(A, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}