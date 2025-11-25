#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int f, f0, f1;
    f0 = 0;
    f1  = 1;
    for(int i=0; i<n; i++){
        f = f0 + f1;
        f0 = f1;
        f1 = f;
        cout<<f<<' ';
    }
    cout<<f;
}