#include<iostream>
using namespace std;
int main()
{
    int var;
    float f;
    char c;
    string str; //string is class /container in c++ default size is 32 bytes for 64 bit
    //read values from user
    cout << "Enter the values for int,float ,char and str:\n";
    cin >> var >> f >> c;
    cin.ignore(); // is a function in c++ used to ignore or skip characters int the input buffer
    getline(cin, str); //read the i/p chars until newline is encountered
    //print the values
    cout << "Value is var: " << var << endl; // << "\n" ; also works instead of endl
    cout << "Value are : " << f << endl << c << endl << str << endl;
    return 0;

}