
#include<iostream>

using namespace std;

string add_binery(string s1, string s2){
    string s = "";
    int tmp = 0;
    string padding = "";
    for(int i=0; i<s1.length() - s2.length(); i++){
        padding += '0';
    }
    s2 = padding + s2;
    for(int i=s1.length()-1; i>=0; i--){
        int sum = (s1[i] -'0') + (s2[i] - '0') + tmp;
        if(sum == 0) {
            s = '0' + s;
            tmp = 0;
        }
        if(sum == 1){
            s = '1' + s;
            tmp = 0;
        }
        if(sum == 2){
            s = '0' + s;
            tmp = 1;
        }
        if(sum == 3){
            s = '1' + s;
            tmp = 1;
        }
    }
    if(tmp) s = '1' +s;

    return s;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    string s = s1.length() > s2.length()? add_binery(s1,s2) : add_binery(s2, s1);
    cout<<s;

    return 0;
}
