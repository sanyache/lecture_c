#include<iostream>
#include<sstream>

using namespace std;

int main(){

    string s, word;
    string str_result = "";
    bool first = true;
    getline(cin, s);
    stringstream ss(s);
    while(getline(ss, word, ' ')){
        if(word.empty()){
            if(first) str_result = ' ';
            continue;
        }
        str_result +=word +' ';
        first = false;
    }
    if(! word.empty())  str_result.erase(str_result.size()-1, 1);
    cout<<str_result<<'\n';
    return 0;
}
