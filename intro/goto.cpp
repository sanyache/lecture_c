#include <iostream>

using namespace std;

int main(){
    int i=0;
    int x(5);
    int y{1};
    cout<<"Start\n";
CIRCLE:
    if(i>3) goto EXIT;
    cout<<"A\n";
    cout<<"B\n";
    cout<<"C\n";
    i = i + 1;
    goto CIRCLE;
EXIT:
    cout<<"End"<<'\n';
    cout<<x<<'\t'<<y;
    return 0;
}
