#include<iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int prev_0 = 0;
    int prev_dig = 1;
    for(int i=2; i<=n; i++){
        int current_0 = prev_dig;
        prev_dig = (prev_0 + prev_dig)*(k-1);
        prev_0 = current_0;
    }
    cout<<(prev_dig + prev_0)*(k-1);
    return 0;
}
//Обрахувати кількість n-значних чисел в системі числення 
// з основою k, таких, які не містять двох нулів підряд
// 2<=k<=10; 2<=n; 4<=n+k<=18
//2 10 90
//4 2 5
//6 3 328