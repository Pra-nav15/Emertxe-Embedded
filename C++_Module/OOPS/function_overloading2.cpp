#include<iostream>
using namespace std;
class FunctionOverloading
{
    public:
        void calculation(int a,int b,int k)
        {
            cout << "The sum is = " << a + b + k << endl;
        }
        void calculation(double a,double b,double k)
        {
            cout << "Multiplication is = " << a * b * k << endl;
        }
        void calculation(int a,int b)
        {
            cout << "The division is = " << a/b << endl;
        }
};
int main()
{
    FunctionOverloading obj;
    obj.calculation(4,10,4);
    obj.calculation(4.5,5.3,6.5);
    obj.calculation(10,5);
    return 0;
}
