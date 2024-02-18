#include<iostream>

using namespace std;

int main(){

    string s;
    int counter=0;
    char c, cc;
    getline(cin, s);
    cin>>c;
    if(islower(c)) cc = toupper(c);
    else cc = tolower(c);
    for(size_t i=0; i<s.size(); i++){
        if(s[i] == c || s[i]==cc)
            counter ++;
    }
    cout<<counter;
 return 0;
}
