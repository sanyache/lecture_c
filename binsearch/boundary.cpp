#include<iostream>
#include<vector>


using namespace std;

int left_boundary(const vector<int> &A, int n){
    int left = -1;
    cout<<(left < A.size())<<'\n';
    while(left < int(A.size()) and A[left + 1] < n){
        left ++;
    }
    return left;
}

int right_boundary(const vector<int> &A, int n){
    int right = A.size();
    while( right > 0 and A[right - 1] > n ){
        right --;
    }

    return right;
}

int bin_right_boundary(const vector<int> &A, int n){

    int left = -1;
    int right = A.size();
    while(right - left > 1){
        int mid = (left + right)/2;
        if (A[mid] > n){
            right = mid;
        } else {
            left = mid;
        }

    }
    return right;
}

int bin_left_boundary(const vector<int> &A, int n){

    int left = -1;
    int right = A.size();
    while(right - left > 1){
        int mid = (left + right)/2;
        if(A[mid] < n){
            left = mid;
        } else {
            right = mid;
        }

    }
    return left;

}

int main(){

    vector<int> A = {2,2,2,5,5,7,7,9};
    cout<<left_boundary(A, 7)<<'\n';
    cout<<right_boundary(A, 7)<<'\n';
    cout<<bin_left_boundary(A, 7)<<'\n';
    cout<<bin_right_boundary(A, 7)<<'\n';
    return 0;
}
