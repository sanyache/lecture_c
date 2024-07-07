#include<iostream>

using namespace std;

const int maxN = 51;

uint64_t fib_dynamic(int n){
    static uint64_t F[maxN];
    if(n==0) return F[0] = 0;
    if(n==1) return F[1] = 1;
    F[n] = F[n-1] + F[n-2];
    return F[n];
}

int main(){

    
    for(int i=0; i<maxN; i++){
        cout<<i<<'\t'<<fib_dynamic(i)<<'\n';
    }
    return 0;
}
