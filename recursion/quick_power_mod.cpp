#include<iostream>

using namespace std;

typedef long long   ll;

ll pow(ll a, ll n, ll mod){
    cout<<n<<'\n';
    if(n == 0) return 1;
    if(n%2 == 0)
        return pow(a*a%mod, n/2, mod);
    else
        return (pow(a, n-1, mod)*a)%mod;
}

int main(){
    const ll mod = 1000000007;
    cout<<pow(2, mod-2, mod);

    return 0;
}
