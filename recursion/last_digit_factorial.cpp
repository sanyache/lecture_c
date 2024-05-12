#include<iostream>
using namespace std;

int main()
{
    int i,t,ost0,ost1;
    long int n;
    cin>>n;
    ost0=1;
    ost1=1;
    if(n==0||n==1){cout<<"1";return 0;}
    for(i=2;i<=n;++i)
    {   t=ost1;
        ost1=(ost1+ost0)%10;
        ost0=t;
    }
    cout<<ost1;
    return 0;
}
