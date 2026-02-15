#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> A;
    int n = 100;
    for(int i=n-1; i>=0; i--){
        A.push_back(i);
    }
    int i=0;
    int cnt = 0;
    while (i<n-1)
    {
        cnt ++;
        if(A[i] > A[i+1]){
            swap(A[i], A[i+1]);
            i = 0;
            continue;
        }
        i ++;
    }
    for(int i=0; i<n; i++){
        cout<<A[i]<<' ';
    } 
    cout<<'\n'<<cnt;
    
}