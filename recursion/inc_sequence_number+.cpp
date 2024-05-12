#include<iostream>

using namespace std;

int sequence(int n){

    if (n==1) {
        cout<<n;
        return 1;

    }
    sequence(n-1);
    cout<<'+'<<n;
    return n;
}

int main(){

    int n;
    cin>>n;
    sequence(n);
    return 0;
}
