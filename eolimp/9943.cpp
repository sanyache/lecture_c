#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    int64_t m;
    cin>>n>>m;
    int64_t low_limit;
    int64_t up_limit = pow(10, n) -1;
    int64_t counter  = 0;
    if (n == 1) {
        low_limit = 2;
    } else {
        low_limit = pow(10, n-1);
    }
    if(m > low_limit) {
        up_limit = min(up_limit, m);
        counter = (up_limit - low_limit + 1)/2;
    }
    cout<<counter;
    return 0;
}
