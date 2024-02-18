#include<iostream>

using namespace std;

int main(){

    int n;
    cin>>n;
    bool E[n + 1];
    for(int i=2; i<=n; i++){
        E[i] = true;
    }
    for(int x=2; x*x < n; x++){
        if(E[x]){
            for(int j=x*x; j<=n; j+=x){
                E[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(E[i]) cout<<i<<' ';
    }
    return 0;
}
