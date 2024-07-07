#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

    vector<int> A = {6,2,5,1,7,4,8,3};
    int n = size(A);
    vector<int> L (n, 1);

    for(int k=1; k<n; k++){
        for(int i=0; i<k; i++){
            if(A[i] < A[k]){
                L[k] = max(L[k], L[i]+1);
            }
        }
    }
    cout<<*max_element(L.begin(), L.end())<<'\n';
    return 0;
}