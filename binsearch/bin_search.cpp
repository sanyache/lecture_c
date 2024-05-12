#include<iostream>
#include<vector>


using namespace std;

int  bin_search(const vector<int> &A, int item){
    int left = 0;
    int right = A.size();
    while(right >= left){
        int middle = (left+right)/2;
        if(item == A[middle]) return middle;
        if(item < A[middle]){
            right = middle -1;
        } else {
            left = middle +1;
        }
    }
    return -1;
}

int main(){

    vector<int> A = {10, 20, 30, 40, 50, 60};
    int x;
    cin>>x;
    int ind = bin_search(A, x);
    cout<<ind;
    return 0;
}
