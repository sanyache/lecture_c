#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(const char& c1, const char& c2){
    if (isupper(c1) && islower(c2)) return false;
    if (islower(c1) && isupper(c2)) return true;

    return (c1 < c2);
}

int main(){

    string word1 = "GameA";
    string word2 ("over");
    string word3(3, '!');
    string phrase = word1 + ' ' + word2 + ' ' + word3;
    cout<<phrase<<'\n';
    cout<<phrase.size()<<'\n';
    cout<<phrase[phrase.length()-1]<<'\n';
    cout<<phrase[phrase.length()]<<'\n';
    for(unsigned int i=0; i<phrase.size(); i++){
        cout<<phrase[i]<<' ';
    }
    cout<<'\n';
    for(const auto ch: phrase){
        cout<<ch<<' ';
    }
    cout<<'\n';
    for(auto it=phrase.begin(); it!=phrase.end(); it++){
        cout<<*it<<' ';
    }
    size_t position = phrase.find("!");
    if(position != string::npos){
        cout<<'\n'<<phrase.find("!", position+1)<<'\n';
    }
    cout<<'\n';
    reverse(phrase.begin(), phrase.end());
    cout<<phrase<<'\n';
    cout<<"sorted string: ";
    sort(phrase.begin(), phrase.end(), cmp);
    cout<<phrase;
    cout<<"is lower"<<islower('a')<<' '<<islower('k');
    return 0;
}
