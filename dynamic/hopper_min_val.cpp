#include<iostream>

using namespace std;

int main(){

    int n;
    cout<<"Enter number of steps= ";
    cin>>n;
    int val[n], total[n];
    cout<<"Enter value for every step ";
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    total[0] = val[0];
    total[1] = min(val[0] + val[1], val[1]);
    for(int i=2; i<n; i++){
        total[i] = min(total[i-1], total[i-2]) + val[i];
        cout<<total[i]<<'\n';
    }
    cout<<total[n-1]<<'\n';
    int current_price = total[n-1]-val[n-1];
    int current_index = n-1;
    while(current_price>0){
        
        if(total[current_index-1] < total[current_index-2]){
            current_index = current_index - 1;
        } else {
            current_index = current_index - 2;
        }
        cout<<"ind="<<current_index<<' '<<val[current_index]<<' ';
        current_price -= val[current_index];
        
    }
    return 0;
}