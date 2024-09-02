#include<iostream>

using namespace std;

template<typename T>
T add_numbers(T a, T b){

    return a+b;
}

int main(){

    int a = 2;
    int b = 3;
    cout<<add_numbers(a,b)<<'\n';
    float f_a = 2.3;
    float f_b = 3.2;
    cout<<add_numbers(f_a, f_b)<<'\n';
    string s_a = "2";
    string s_b = "3";
    cout<<add_numbers(s_a, s_b)<<'\n';
    return 0;
}
