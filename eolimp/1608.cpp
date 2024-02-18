#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    string s, tmp;
    cin>>s;
    tmp = s;
    reverse(s.begin(), s.end());
    cout<<(tmp == s?"Yes":"No");
    return 0;
}
