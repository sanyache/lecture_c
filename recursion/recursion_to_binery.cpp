#include<iostream>

using namespace std;

void recursion_to_bin(int n){
    if(n == 0) return;
    recursion_to_bin(n/2);
    cout<<n%2;
    return;
}

int main(){

    int n;
    cin>>n;
    recursion_to_bin(n);
    return 0;
}
