#include<iostream>

using namespace std;

double pow(double a, int n){
    cout<<n<<'\n';
    if(n == 0) return 1;
    if(n%2 == 0)
        return pow(a*a, n/2);
    else
        return pow(a, n-1)*a;
}

int main(){
    cout<<pow(1.0000023, 6438000);

    return 0;
}
