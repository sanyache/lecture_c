#include<iostream>


using namespace std;

int main(){
    int64_t n;
    cin>>n;
    int counter = 0;
    if(n == 0) counter = 1;
    while(n > 0){
        counter ++;
        n = n/10;

    }
    cout<<counter;


    return 0;
}
