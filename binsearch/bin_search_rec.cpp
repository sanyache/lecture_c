#include<iostream>
#include<vector>

using namespace std;

int bin_search(const vector<int> &A, int x, int left=0, int right=-2){
    right = (right != -2) ? right : (A.size()-1);
    if (right >= left){
        int mid = (left + right)/2;
        if (A[mid] == x) return mid;
        if  (x < A[mid]) {
            bin_search(A, x, left, mid-1);
        }  else {
            bin_search(A, x, mid+1, right);
        }
    } else{
        return -1;
    }
}

int main(){

    vector<int> A = {2, 5, 8, 12,16, 23, 38, 56, 72, 91};
    int n = A.size();
    cout<<bin_search(A, 2);
    return 0;
}
