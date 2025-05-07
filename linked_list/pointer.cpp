#include<iostream>

using namespace std;

int main(){
    int* pScore = nullptr;
    int score =  1000;
    pScore = &score;
    cout<<"pScore="<<pScore<<endl;
    cout<<"*pScore="<<*pScore<<endl;
    score +=500;
    cout<<"pScore"<<pScore<<endl;
    cout<<"*pScore"<<*pScore<<endl;
    pScore += 1;
    cout<<"pScore"<<pScore<<endl;
    cout<<"*pScore"<<*pScore<<endl;
    int new_score = 2000;
    pScore = &new_score;
    cout<<"pScore="<<*pScore<<endl;
    string str = "Score";
    string* pStr= &str;
    cout<<"str size="<<(*pStr).size()<<endl;
    cout<<"str size="<<pStr->size()<<endl;
    return 0;
}