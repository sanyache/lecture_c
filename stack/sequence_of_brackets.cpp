#include<iostream>


using namespace std;


int main(){

    int n=0;
    string s;
    cin>>s;
    for(size_t i=0; i<s.size(); i++){

        if(s[i] == '(') n++;
        if(s[i] == ')') n--;
        if(n < 0) break;
    }
    cout<<"sequence is "<<(n == 0?"":"not ")<<"correct";
    return 0;
}
