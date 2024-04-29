#include<iostream>


using namespace std;

int fib(int n){
    if(n <= 1) {
        return n;
    }
    int f = (fib(n-1) + fib(n-2));
    return f;
}

int main(){

    int n;
    cin>>n;
    fib(n);
    for(int i=1; i<=n; i++)
        cout<<fib(i)<<' ';
    return 0;
}
