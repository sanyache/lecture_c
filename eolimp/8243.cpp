#include<iostream>


using namespace std;

int main(){

    string s;
    cin>>s;
    cout<<(s[0] == '-'? s[1] : s[0]);
    return 0;
}
