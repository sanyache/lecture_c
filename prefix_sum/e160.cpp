#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n];
    string s;
    cin>>s;
    for(int i=0; i<n; i++){
        if(s[i] == 'b'){
            A[i] = 1;
            
        } else {
            A[i] = 0;
        }
    }
    uint32_t prefix_sum[n+1] = {0};
    for(int i=1; i<n+1; i++){
         prefix_sum[i] = (prefix_sum[i-1] + A[i-1]);
    }
    uint32_t counter = 0;
    for(int  i=1; i<n; i++){
        for(int j=i+1; j<n+1; j++){
            int sum = prefix_sum[j] -prefix_sum[i-1];
            if (sum!=0 and (j-i+1)>1 and (j-i+1) == 2 * sum){
                counter ++;
            }    
        }
    } 
    cout<<counter;           
    return 0;
}