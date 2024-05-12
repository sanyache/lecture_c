#include<iostream>
#include<iomanip>

using namespace std;

double f(double x){

    return (x-12.34567)*(x-0.12345);
}

int main(){

    double a,b,c;
    cin>>a>>b;
    double error;
    cin>>error;
    if(f(a)*f(b)<0){
        while((b-a)/2.0>error){
            c = (a+b)/2.0;
            if(f(c) == 0) return c;
            if (f(a)*f(c)<0){
                b = c;
            } else {
                a = c;
            }
        }

    } else{
        cout<<"data is not correct";
    }
    cout<<setprecision(10)<<c;
    return 0;
}
