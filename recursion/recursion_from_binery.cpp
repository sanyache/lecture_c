#include<iostream>

using namespace std;

int recursion_from_bin(int n, int decimal, int pow){
    if(n==0) return decimal;
    if(n%10==1) decimal += pow;
    pow *= 2;
    return recursion_from_bin(n/10, decimal, pow);
}

int main(){
    int n;
    cin>>n;
    cout<<recursion_from_bin(n, 0 , 1);
    return 0;
}
