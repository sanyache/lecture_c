#include<iostream>

using namespace std;

int count_house(int A[], int n, int length){
    int counter = 0;
    for(int i=0; i<n; i++)
        counter += A[i]/length;
    return counter;
}

int main(){

    int n, k;
    cin>>n>>k;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    int left = 0;
    int right = 10000001;
    int mid = 0;
    while(right -left > 1){
        mid = (left + right)/2;
        int houses = count_house(A, n, mid);
        if(houses >= k){
            left = mid;
        }else{
            right = mid;
        }

    }

    cout<<right-1;
    return 0;
}
