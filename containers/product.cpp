#include<iostream>
#include<unordered_map>
#include<utility>

using namespace std;

void print_products(unordered_map<string, float> &products){
    for(auto [product, price]: products){
        cout<<product<<' '<<price<<'\n';
    }
}

pair<string, float> find_product(unordered_map<string, float> &products, string &product){
    pair<string, float> rez;
    if(products.find(product) != products.end()){
        rez = make_pair(product, products[product]);
    } else {
        rez = make_pair("Not found", 0);
    }
    return rez;
}

int main(){

    int n;
    cout<<"Enter number of product? ";
    cin>>n;
    unordered_map<string, float> products;
    for(int i=0; i<n; i++){
        cout<<"Enter product and price: ";
        string product;
        float price;
        cin>>product>>price;
        products[product] = price;
    }
    print_products(products);
    cout<<"Enter product for seek ";
    string product;
    cin>>product;
    pair<string, float> find_pair;
    find_pair = find_product(products, product);
    cout<<find_pair.first<<' '<<find_pair.second;
    return 0;
}
