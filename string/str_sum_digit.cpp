#include<iostream>
#include<cctype>

using namespace std;

int main(){

    string s;
    string s_number = "123456";
    cin>>s;
    int sum = 0;
    for(unsigned int i=0; i<s.size(); i++){
        if(isdigit(s[i])){
            sum += s[i] -'0';
        }
    }
    cout<<sum<<'\n';
    cout<<stoi(s_number)+4<<'\n';
    return 0;
}
