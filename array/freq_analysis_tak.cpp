#include<iostream>

using namespace std;

int main(){
    int A[900]={0};
    string s;
    cin>>s;
    if (s.size() < 3)
    {
        cout<<0;
        return 0;
    }
    int counter = 0;
    for(size_t i=0; i<s.size()-2; i++){
        if (s[i] == '0') continue;
        int ind = ((s[i]-'0')*100 + (s[i+1]-'0')*10 +s[i+2]-'0');
        cout<<ind<<'\n';
        A[ind] ++;
    }
    for(int i=0; i<900; i++){
        if (A[i] != 0) counter ++;
    }
    cout<<counter;
    return 0;
}
