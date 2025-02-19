// sorting the numbers that are in the range of 0 to 100
// using counter sort
#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int A[100] = {0};
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        A[x]++;
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<A[i]; j++){
            cout<<i<<" ";
        }
    }
    return 0;
}