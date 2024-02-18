#include<iostream>
#include<vector>

using namespace std;

int main(){

    string s, postfix="";
    vector<char>A;
    cin>>s;
    A.resize(s.size());
    for(auto ch:s){
        if(isdigit(ch)) {
            postfix += ch;
            continue;
        }
        if(ch == '(') continue;
        if(ch == ')') {
            postfix += ' ';
            postfix += A[A.size()-1];
            postfix += ' ';
            A.pop_back();
        } else {
            A.push_back(ch);
            postfix += ' ';
        }
    }
    while(!A.empty()){
        postfix += ' ';
        postfix += A[A.size()-1];
        postfix += ' ';
        A.pop_back();
    }
    cout<<postfix;
    return 0;
}
