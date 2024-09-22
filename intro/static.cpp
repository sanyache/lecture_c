#include<iostream>
using namespace std;

int add_one(){
    static int y = 1;
    return y++;
}

int main(){

    for(int i=1; i<=5; i ++){
        cout<<add_one()<<' ';
    }
    return 0;
}
