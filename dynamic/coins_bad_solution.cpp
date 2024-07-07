#include<iostream>

using namespace std;

int main(){
    int n = 12;
    int coins[] = {1, 2, 5};
    int len = sizeof(coins)/sizeof(coins[0]);
    int counter = 0;
    int i = 0;
    while (n > 0)
    {
        counter += n/coins[len-i-1];
        n = n%coins[len-i-1];
        i++;
    }
    cout<<"k= "<<counter; 

    return 0;
}