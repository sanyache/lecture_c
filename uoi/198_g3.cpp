#include<iostream>


using namespace std;

int limit(vector<int> &A){
    int k = 0;
    int l = 0;
    int r = A.size()-1;
    if(A[l] == A[r]) return r;
    while(r-l >1){
        int mid = (r+l)/2;
        if(A[mid] < A[r]){
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main(){

    vector<int> b = {0, 0, 0, 0,};
    vector<int> a = {1, 1, 1, 1,1 };
    int k1 = limit(a);
    int k2 = limit(b);
    cout<<k1<<' '<<k2<<'\n';
    int k= 2;
    int curr_k = 0;
    if (a[k1] < b[k2]){
        curr_k = k1;
        if(curr_k >= k){
            cout<<a[k1];
        } else {
            cout<<b[b.size()-1];
        }
    }
    if (a[k1] == b[k2]){
        curr_k = k1 +k2 + 2;
        if(curr_k >= k){
            cout<<a[k1];
        } else {
            cout<<max(a[a.size()-1], b[b.size()-1]);
        }
    }
    if (a[k1] > b[k2]){
        curr_k = k2;
        if(curr_k >=k){
            cout<<b[k2];
        } else {
            cout<<a[a.size()-1];
        }
    }



    return 0;
}
