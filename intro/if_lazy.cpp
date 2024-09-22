#include<iostream>

using namespace std;

int main(){

    int x = 0;
    int y = 2;
    bool flag;
    flag = (++x == 1) or (y ++ == 2);
    cout<<"flag="<<flag<<" x="<<x<<" y="<<y<<'\n';
    x = 0; y = 2;
    flag = (x++ == 1) or (y ++ == 2);
    cout<<"flag="<<flag<<" x="<<x<<" y="<<y<<'\n';
    x = 0; y = 2;
    flag = (x++ == 1) and (y ++ == 2);
    cout<<"flag="<<flag<<" x="<<x<<" y="<<y<<'\n';
    x = 0; y = 2;
    flag = (++ x == 1) and ( y ++ == 1);
    cout<<"flag="<<flag<<" x="<<x<<" y="<<y<<'\n';
    return 0;
}
