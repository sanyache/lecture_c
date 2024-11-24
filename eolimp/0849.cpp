#include<iostream>


using namespace std;

int sequence(int base, int n){
    if(n == base) {
        cout<<n<<'+';
        return base;
    }
    cout<<base<<'+'<<n<<'\n';

    sequence(base, n-1);

    return n;
}

int main(){

    int n;
    cin>>n;
    int left = 1;
    int right = n-1;
    while(left<=right){
        sequence(left, right);
        left ++;
        right --;
    }
    return 0;
}
