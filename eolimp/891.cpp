#include<iostream>

using namespace std;


int main(){
    int a,b,c;
    int max_price=0;
    int price = 0;
    int max_counter = 0;
    int counter = 0;
    cin>>a>>b>>c;
    for(int i=0; i<=c; i+=a){
        for(int j=0; j<=c; j+=b){
            price = i + j;
            if(price > c) break;
            counter = i/a + j/b;
            if(counter > max_counter) {
                max_price = price;
                max_counter = counter;
            }
        }
    }
    cout<<max_price;
    return 0;
}
