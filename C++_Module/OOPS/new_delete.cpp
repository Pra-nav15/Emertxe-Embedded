#include<iostream>
using namespace std;

int main()
{
    int* ptr = new int[4];
    for (int i = 0;i < 4;i++) // int array of 4 elements allocate memory
    {
        cin >> ptr[i];
        cout << ptr[i] << endl;
    }
    delete ptr; //deallocate memory
    return 0;
}