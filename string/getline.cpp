#include<iostream>
#include<sstream>
using namespace std;

int main(){

    string name, first_name, last_name, part_name;
    //cin>>first_name>>last_name;
    //cout<<first_name<<"   "<<last_name;
    getline(cin, name);
    string max_word = "";
    string min_word = name;
    cout<<name<<'\n';
    stringstream stream_s(name);
    while(getline(stream_s, part_name, ' ')){
        if(part_name.size() > max_word.size()) max_word = part_name;
        if(part_name.size() < min_word.size()) min_word = part_name;
        //cout<<part_name.size()<<'\n';
    }
    cout<<"min word"<<min_word<<'\n';
    cout<<"max word"<<max_word<<'\n';
    return 0;
}
