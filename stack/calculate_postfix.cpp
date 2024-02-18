#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int main(){
    string s, word;
    int tmp;
    vector<int> Stack;
    getline(cin, s);
    stringstream s_stream(s);
    while(s_stream>>word){
        if( word == "+") {
            tmp = Stack[Stack.size()-1] + Stack[Stack.size()-2];
            Stack.pop_back();
            Stack.pop_back();
            Stack.push_back(tmp);
            continue;
        }
        if( word == "*") {
            tmp = Stack[Stack.size()-1] * Stack[Stack.size()-2];
            Stack.pop_back();
            Stack.pop_back();
            Stack.push_back(tmp);
            continue;
        }
        Stack.push_back(stoi(word));

    }
    cout<<Stack[0];

    return 0;
}
