#include<iostream>

using namespace std;


int main(){
    string s;
    int k;
    cin>>s>>k;
    for(size_t i=0; i<s.size(); i++){
        int shift = (s[i] - k) < 65 ? (91 - (65 - s[i]+k)) : s[i]-k;
        char al = shift;
        cout<<al;
    }
    return 0;
}
