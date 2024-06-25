#include<iostream>

using namespace std;

uint64_t fib_dynamic(int n){
    uint64_t F[n+1];
    F[0] = 0;
    F[1] = 1;
    for(int i=2; i<=n; i++){
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];
}

int main(){

    int n;
    cin>>n;
    for(int i=0; i<=n; i++){
        cout<<i<<'\t'<<fib_dynamic(i)<<'\n';
    }
    return 0;
}
