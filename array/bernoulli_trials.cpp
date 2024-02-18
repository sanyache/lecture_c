#include<iostream>
#include<cstdlib>

using namespace std;

bool flip(){

 return rand() < RAND_MAX/2;
}

int main(){
    int n, m;
    cin>>n>>m;
    int A[n];
    for(int i=0; i<n; i++) A[i] = 0;
    for(int i=0; i<m; i++){
        int counter = 0;
        for(int j=0; j<n; j++){
            if(flip()) counter ++;
        }
        A[counter] ++;
    }
    for(int i=0; i<n; i++){
        if(A[i] == 0) cout<<'.';
        else{
            for(int j=0; j<A[i]; j+=10){
                cout<<'*';
            }
        }
        cout<<'\n';
    }

    return 0;
}
