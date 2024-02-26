#include<iostream>

using namespace std;

void bad_counter(int item){

     ++item;
}
void good_counter(int &item){

     ++item;
}
int main(){
    int counter=0;
    int &link_counter = counter;
    cout<<"link counter="<<link_counter<<'\n';
    bad_counter(counter);
    cout<<"counter after bad_counter="<<counter<<'\n';
    good_counter(counter);
    cout<<"counter after good_counter="<<counter<<'\n';
    cout<<"link_counter after increase counter="<<link_counter<<'\n';
    link_counter++;
    cout<<"counter after increase link counter="<<counter<<'\n';
    string str = "counter";
    string &rStr = str;
    cout<<"str.size()="<<str.size()<<endl;
    cout<<"rStr.size()="<<rStr.size()<<endl;
    return 0;
}
