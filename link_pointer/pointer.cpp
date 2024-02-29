#include<iostream>

using namespace std;

int main(){

    int* pScore;
    int score = 1000;
    pScore = &score;
    cout<<"score="<<score<<'\n';
    cout<<"&score="<<&score<<'\n';
    cout<<"*pScore="<<*pScore<<'\n';
    cout<<"pScore="<<pScore<<'\n';
    cout<<"Add 500 to score"<<'\n';
    score += 500;
    cout<<"score="<<score<<'\n';
    cout<<"*pScore="<<*pScore<<'\n';
    int new_Score = 2000;
    pScore = &new_Score;
    cout<<pScore<<endl;
    string str = "Score";
    string* pStr = &str;
    cout<<"str="<<str<<'\n';
    cout<<"*pStr="<<*pStr<<'\n';
    cout<<"str.size()="<<str.size()<<'\n';
    cout<<"(*pStr).size()="<<(*pStr).size()<<endl;
    cout<<"pStr->size()="<<pStr->size()<<endl;
    return 0;
}
