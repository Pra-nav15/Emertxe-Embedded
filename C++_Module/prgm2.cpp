#include<iostream>
using namespace std;
int main()
{
    int var;
    float f;
    char c;
    string str; //string is class /container in c++ default size is 32 bytes for 64 bit
    //read values from user
    cout << "Enter integer value : ";
    cin >> var; //cin read value
    cout << "Enter float value : ";
    cin >> f;
    cout << "Enter char value : ";
    cin >> c;
    cout << "Enter the string : ";
    cin >> str;

    //print the values
    cout << "Value is var: " << var << endl; // << "\n" ; also works instead of endl
    cout << "Value are : " << f << endl << c << endl << str << endl;
    //to display msg
    cout << "Hello World\n"; // for string '\n' can be used

}