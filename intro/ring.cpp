#include<iostream>

using namespace std;

int main(){

      for(int8_t i=100; i<120; i++){

        cout<<i<<' ';

    }
    uint8_t x = 0;
    int8_t y = 1;
    cout<<"x= "<<x-y<<'\n';
//    for(int8_t i=0; i<=128; i++){
//        cout<<int(i)<<' ';
//    }
//    for(uint8_t i=10; i>=0; i--){
//        cout<<int(i)<<' ';

//    }
    int max_el;
    int n = 10;
    int m = max(max_el, n);
    cout<<m<<'\n';
    size_t len = 10;
    int ind = -1;
    cout<<(len > ind)<<'\n';
    return 0;
}
