#include <iostream>

using namespace std;

int main(){
    int s = 0;
    while(true){
        int x;
        cin>>x;
        if(x == 0) break;
        s += x;
    }
    cout<<"Sum of numbers "<<s<<endl;
    return 0;
}
