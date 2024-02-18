#include<iostream>

using namespace std;

int main(){

    string s, CamelCase;
    getline(cin, s);
    CamelCase = toupper(s[0]);
    for(size_t i=1; i<s.size(); i++){
        if(s[i] == ' '){
            s[i+1] = toupper(s[i+1]);
            continue;
        }
        CamelCase +=s[i];
    }
    cout<<CamelCase;

    return 0;
}
