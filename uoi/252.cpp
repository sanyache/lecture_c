#include<iostream>
#include<vector>

using namespace std;


 int main(){
    int x, d;
    cin>>x>>d;
    vector<int> prime, rez;
    if(x<d){
        cout<< x;
        return 0;
    }
    int p = 2;
    int n = x;
    while(p*p <= x){
        if(n%p == 0){
            if(p > d){
                cout<<"-1";
                return 0;
            }
            prime.push_back(p);
            n /= p;
        } else {
            p ++;
        }    
    }
    if(n >1 ){
        if(n > d){
            cout<<"-1";
            return 0;
        }
        prime.push_back(n);
    }
    int l = 0;
    for(int r=prime.size()-1; r>=0; r--){
        if(l > r){
            break;
        } else {
            int suf = 1;
            while(l != r and prime[r] * suf*prime[l] <= d){
                suf *= prime[l];
                l ++;
            }
            rez.push_back(prime[r] * suf);
            
        }
    }
    cout<<rez.size()<<'\n';
    for(auto el: rez){
        cout<<el<<' ';
    }
    return 0;
}