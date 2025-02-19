#include <iostream>

using namespace std;

int main()
{
    char mystring[] = "string";
    std::cout << mystring << " has " << sizeof(mystring)<<'\t'<<sizeof(mystring[0]) << " characters.\n";
    for (int index = 0; index < sizeof(mystring); ++index)
        std::cout << int(mystring[index]) << " ";
    //mystring[6] = 'a';
    //mystring[7] = 'b';
    std::cout<<mystring<<'\n';
    int cod_letter = 97;
    char ch = cod_letter;
    cout<<ch<<'\n';
    char letter = 65 + 2;
    cout<<letter<<'\n';
    cout<<"'1'+'0'="<<'1'+ '0'<<'\t'<<char('1' + '0')<<'\n';
    char ch_dig = '5';
    cout<<ch_dig - '0' + 6<<'\n';
    cout<<char('z'-'a'+'A')<<'\n';
    char l = 'A';
    cout<<islower(l);
    return 0;
}
