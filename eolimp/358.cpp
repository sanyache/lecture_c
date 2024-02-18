#include<iostream>
using namespace std;

int main(){
    int D[] = {6, 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
    string number;
    cin>>number;
    int counter = 0;
    for(int i=0; i<number.size(); i++){
        counter += D[number[i]-'0'];
    }
    cout<<counter;
    return 0;
}
