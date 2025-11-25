#include<iostream>
#include<vector>

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
    }
    cout<<"min value= "<<total[n-1]<<'\n';
    int current_price = total[n-1] - val[n-1] ;
    int current_index = n-1;
    vector<int> path;
    path.push_back(val[n-1]);
    while(current_index > 0){
        
        if(total[current_index] == total[current_index-1] + val[current_index]){
            current_index = current_index - 1;
        } else {
            current_index = current_index - 2;
        }
        path.push_back(val[current_index]);
        current_price -= val[current_index]; 
    }

    for(int i = path.size()-1; i >= 0; i--){
        cout<<path[i]<<' ';
    }
    return 0;
}
// n = 10
// -5 7 20 1 1 20 2 10 1 1
// -5 7 1 1 2 1 1