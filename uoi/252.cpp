#include<iostream>
#include<vector>

using namespace std;


 int main(){
    int x, d;
    cin>>x>>d;
    vector<int> prime, rez;
    if(x<d){
        cout<<1<<'\n';
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
    int int_sq = static_cast<int>(std::sqrt(x)); 
    for(int i=min(d, int_sq); i>=2; i--){
        bool is_end = false;
        while(x%i==0){
            rez.push_back(i);
            if(x/i <= d and x/i > 1){
                rez.push_back(x/i);
                is_end  =true;
                break;
            } else {
                x /= i;
            }
        }
        if(is_end) break;
    }
    cout<<rez.size()<<'\n';
    for(auto el: rez){
        cout<<el<<' ';
    }
    return 0;
}