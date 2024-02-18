#include<iostream>

using namespace std;


int main(){

    string s;
    cin>>s;
    for(size_t i=0; i<s.size(); i++)
    {
        if(isdigit(s[i]) && (s[i]-'0') % 2 != 0){
            continue;
        } else {
            cout<<s[i];
        }

    }
    return 0;
}
