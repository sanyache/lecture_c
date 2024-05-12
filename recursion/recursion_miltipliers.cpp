#include<iostream>


using namespace std;

void recursion_multipliers(int n, int d){
    if( n == 1) return;
    if(n%d == 0) {
        cout<<d<<' ';
        recursion_multipliers(n/d, d);

    } else{
        recursion_multipliers(n, ++d);
    }
}

int main(){

    int n;
    cin>>n;
    recursion_multipliers(n ,2);
    return 0;
}
