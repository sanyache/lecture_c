#include<iostream>


using namespace std;


int main(){

    string s;
    int counter = 0;
    getline(cin, s);
    for(size_t i=0; i<s.size(); i++){
        if(isupper(s[i])) counter ++;
    }
    cout<<counter;
    return 0;
}
