#include<iostream>

using namespace std;

int recursion_from_bin(int n, int decimal = 0, int pow = 1){
    if(n==0) return decimal;
    if(n%10==1) decimal += pow;
    pow *= 2;
    return recursion_from_bin(n/10, decimal, pow);
}

int main(){
    int n;
    cin>>n;
    cout<<recursion_from_bin(n);
    return 0;
}
