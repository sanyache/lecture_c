#include<iostream>
using namespace std;

void bad_counter(int item){
    ++item;
}
void good_counter(int &item){
    ++item;
}
int main(){

    int counter = 0;
    int &link_counter = counter;
    cout<<"link counter"<<link_counter<<endl;
    bad_counter(counter);
    cout<<"counter after bad counter"<<counter<<endl;
    good_counter(counter);
    cout<<"counetr after good counter="<<counter<<endl;
    link_counter ++;
    cout<<"counter after link++="<<counter<<endl;
    int new_counter = 500;
    link_counter = new_counter;
    cout<<"link_counter"<<link_counter<<endl;
    cout<<"counter= "<<counter<<endl;
    counter= 2000;
    cout<<"link counter"<<link_counter<<endl;
    string str = "counter";
    string &rStr = str;
    cout<<"rStr="<<rStr<<endl;
    cout<<"rStr size="<<rStr.size()<<endl;
    for(auto &ch: str){
        cout<<ch<<' ';
    }
    return 0;
}