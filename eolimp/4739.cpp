#include<iostream>

using namespace std;

int main(){

    int a, b;
    cin>>a>>b;
    bool E[b + 1];
    E[1] = false;
    for(int i=2; i<=b; i++){
        E[i] = true;
    }
    for(int x=2; x*x < b; x++){
        if(E[x]){
            for(int j=x*x; j<=b; j+=x){
                E[j] = false;
            }
        }
    }
    for(int i=a; i<=b; i++) {
        if(E[i]) cout<<i<<' ';
    }
    return 0;
}
