#include<iostream>

using namespace std;

bool is_prime(int x){
    int num = x;
    int d = 2;
    while(d*d <= x){
        if(x%d == 0){
            return false;
        }
        d ++ ;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    cout<<"Number is "<<(is_prime(n) ? "": "not ")<<"prime"<<'\n';
    return 0;
}