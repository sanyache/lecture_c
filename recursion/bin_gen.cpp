#include<iostream>


using namespace std;

void bin_gen(int n, string prefix){

    if (n == 0) cout<<prefix<<'\n';
    else{
        bin_gen(n-1, prefix + '0');
        bin_gen(n-1, prefix + '1');
    }
}

int main(){
    bin_gen(4, "");
    return 0;
}
