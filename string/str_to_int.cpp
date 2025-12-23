#include <iostream>
#include<sstream>
using namespace std;

bool is_digit(char ch){

    return '0' <= ch  and ch <= '9';
}

int str_to_int(string &s){
    int n = 0;
    int pow = 1;
    for(int i=s.size()-1; i>=0; i--){
        try{
            if(not is_digit(s[i])) throw "Not digigt";  
        } catch (const char* exc){
            cerr<<"Error"<<exc<<'\n';
        }    
        n += (s[i] - '0') * pow;
        pow *= 10;
    }
    return n;
}

int main() {
   
    string s = "ad9sd12md8";
    for(char ch: s){
        cout<<is_digit(ch)<<' ';
    }

    string dig = "12f9";
    cout<<stoi(dig)<<'\n';
    cout<<str_to_int(dig); 
    return 0;
}