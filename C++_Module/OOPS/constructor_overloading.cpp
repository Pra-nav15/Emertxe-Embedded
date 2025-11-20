#include<iostream>
using namespace std;
class Student
{
    public:
        float area;
        Student() //Default Constructor
        {
            cout << "Constructor with zero args\n";
            area = 0;
        }
        Student(int a,int b) //Default Constructor
        {
            cout << "Constructor with two args\n";
            area = a * b;
        }
        void disp()
        {
            cout << area << endl;
        }
};
int main()
{
    Student stud;
    Student stud2(10,20);
    stud.disp();
    stud2.disp();
    return 0;
}