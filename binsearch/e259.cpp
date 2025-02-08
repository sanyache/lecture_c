#include<iostream>
#include<vector>

using namespace std;

int bin_search(const vector<int> A, int n){
    int left = 0;
    int right = A.size();
    while(right >= left){
        int mid = (left + right)/2;
        if(A[mid] == n){
            return mid;
        }
        if (A[mid] < n){
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

int search(const vector<int> A, const vector<int> B){

    for(int i=B.size()-1; i>=0; i--){
        if(bin_search(A, B[i]) != -1){
            return B[i];
        }
    }
    return -1;
}

int main(){
    int n, m;
    vector<int> data1, data2;
    cin>>n;
    if (n == 0){
        cout<<-1;
        return 0;
    }
    data1.resize(n);
    for(int i = 0; i < n; i++){
        cin>>data1[i];
    }
    cin>>m;
    if (m == 0){
        cout<<-1;
        return 0;
    }
    data2.resize(m);
    for(int i = 0; i < m; i++){
        cin>>data2[i];
    }
    if (n > m){
        cout<<search(data1, data2);
    } else {
        cout<<search(data2, data1);
    }
    return 0;
}