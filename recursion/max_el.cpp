#include<iostream>

using namespace std;

int max_el(int A[], int left, int right){

    if(left == right) return A[left];
    int mid = (left + right)/2;
    int max_l = max_el(A, left, mid);
    int max_r = max_el(A, mid+1, right);
    if(max_l > max_r){
        return max_l;
    } else {
        return max_r;
    }
}


int main(){

    int A[] = {1,2,5,7,8,4,10,9,3,6};
    cout<<max_el(A, 0, sizeof(A)/sizeof(A[0])-1);
    return 0;
}
