#include<iostream>

using namespace std;

int factorial(int n){
    int f;
    cout<<n<<' ';
    if(n == 0 || n == 1){
        cout<<'\n';
        return 1;
    }
    f = n * factorial(n-1);
    cout<< f<<endl;
    return f;

}


int main(){
    int n;
    cin>>n;
    cout<<factorial(n);
    return 0;
}
