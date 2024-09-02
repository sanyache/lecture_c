#include<iostream>

using namespace std;


int main(){

    for(int i = 0; i<20; i++){
        if(i%2 != 0) continue;
        cout<<i<<' ';
    }
    cout<<'\n';
    for(int i= 1; i<20; i +=2){
        cout<<i<<' ';
    }
    cout<<'\n';
    for(int i=20; i>=0; i--){
        cout<<i<<' ';
    }
    return 0;
}
