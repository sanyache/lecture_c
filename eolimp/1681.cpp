#include <iostream>
#include<cmath>

using namespace std;

int64_t get_sum_binery(int64_t number){
    int s = 0;
    while(number > 0){
        int remainder  = number % 2;
        number /= 2;
        s += remainder;
    }
    return s;
}

int64_t get_sum_decimal(int64_t number, int max_sum){
    int s = 0;
    while(number){
        int remainder = number%10;
        number /= 10;
        s += remainder;
        //if(s> max_sum) break;
    }
    return s;
}

int main(){
    int n;
    cin>>n;
    int64_t digit_number = pow(10, n);
    int counter = 0;
    int max_sum_binery = log2(pow(10, n));
    //cout<<max_sum_binery<<endl;
    int cut = 0;
    for(int64_t i=digit_number/10; i<digit_number; i++){
        cut %= 10 ;
        cut ++;
        int sum_decimal = get_sum_decimal(i, max_sum_binery);
        //cout<<sum_decimal<<' ';
        /*if( sum_decimal > max_sum_binery){
            i = i + 10 -cut;
            cut += 10-cut;
            continue ;
        } */
        if(get_sum_binery(i) == sum_decimal){
            counter ++;
        }

    }
    cout<<counter;
    return 0;
}
