#include<iostream>

using namespace std;


double pow(double a, double n){

    if(n == 0) return 1;
    double p = pow(a, n-1)*a;
    cout<<p;
    return p;
}

int main(){

    double a,n;
    cin>>a>>n;
    cout<<pow(a,n);
    return 0;
}
