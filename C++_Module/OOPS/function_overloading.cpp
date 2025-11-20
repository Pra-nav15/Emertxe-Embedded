#include <iostream>
using namespace std;
//function overloading based on parameters inside each function but same function name
int add(int n1, int n2)
{
 return n1 + n2;
}
double add(double n1, double n2)
{
 return n1 + n2;
}
string add(string s1, string s2)
{
// Operator Overloading
 return s1 + s2;
}

int main()
{
    cout << add(5, 10) << endl;
    cout << add(15.5, 6.25) << endl;
    cout << add("Hell", "o") << endl;
    return 0;
}