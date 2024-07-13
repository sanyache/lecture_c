#include<iostream>

using namespace std;

struct Product{
    int price;
    int weight;
};

int max_backpack_value(Product Products[], int n, int capacity){
    int val[n+1][capacity+1];
    for(int i=0; i<=n; i++){
        val[i][0] = 0;
    }
    for(int i=0; i<=capacity; i++){
        val[0][i] = 0;
    }
    for(int i=1; i<=n; i++){
        int price = Products[i].price;
        int weight = Products[i].weight;
        for(int j=1; j<=capacity; j++){
            if(weight > j) {
                val[i][j] = val[i-1][j];
            } else {
                val[i][j] = max(val[i-1][j], price + val[i-1][j-weight]);
            }    
        }
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=capacity; j++){
            cout<<val[i][j]<<' ';
        }
        cout<<'\n';
    }
    return val[n][capacity];
}
int main(){

    int n;
    cout<<"Enter the number of products= ";
    cin>>n;
    cout<<"Enter the price and weight of each product"<<'\n';
    Product Products[n + 1];
    for(int i=1; i<=n; i++){
        Product cur;
        cin>>cur.price>>cur.weight;
        Products[i] = cur;

    }
    int capacity;
    cout<<"Enter the capacity of backpack=";
    cin>>capacity;
    cout<<"Max value= "<<max_backpack_value(Products, n, capacity)<<'\n';
    return 0;
}
// 3
// 1500 1
// 3000 4
// 2000 3
// 4
// answ = 3500