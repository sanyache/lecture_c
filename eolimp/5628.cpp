#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(const char& c1, const char& c2){
    if (c1 == '0') return false;
    return (c1 < c2);
}

int main(){

    string s;
    cin>>s;
    if(s[0] == '-'){
        sort(s.begin()+1, s.end());
        reverse(s.begin()+1, s.end());
    } else {
        sort(s.begin(), s.end(), cmp);
        if(s[2] == '0' && s[1] != '0' ) swap(s[2], s[1]);
    }

    cout<<s;

    return 0;
}
