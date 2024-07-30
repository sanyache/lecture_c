#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int F[n+1];
    F[1] = 1;
    F[2] = 2;
    for(int i=3; i<=n; i++){
        F[i] = F[i-1] + F[i-2];
    }
    cout<<F[n]*2;
    return 0;
}