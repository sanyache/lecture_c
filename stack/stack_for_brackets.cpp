#include<iostream>
#include<vector>

using namespace std;


int main(){
    vector<char> A;
    string s;
    bool correct = true;
    cin>>s;
    A.reserve(s.size());
    for(char ch: s){
        if(ch == '(' or ch == '[') {
            A.push_back(ch);
            continue;
        }
        if(!A.empty()){
            char current = A[A.size()-1];
            A.pop_back();
            if(current == '[' and ch != ']' or current == '(' and ch != ')') correct = false;
        } else  correct = false;
        if(!correct) break;
    }
    cout<<"sequence is "<<(correct and A.empty()? "": "not ")<<"correct";
    return 0;
}
