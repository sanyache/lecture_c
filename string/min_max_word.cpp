#include<iostream>
#include<sstream>
using namespace std;

int main(){

    string s, word;
    getline(cin, s);
    string min_word = s;
    string max_word = "";
    stringstream stream_s(s);
    while(getline(stream_s, word, ' ')){
        if(word.size() > max_word.size()) max_word = word;
        if(word.size() < min_word.size()) min_word = word;
    }
    cout<<"min word "<<min_word<<'\n';
    cout<<"max word "<<max_word;
    return 0;
}
