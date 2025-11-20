#include<iostream>
using namespace std;
class Student
{
public:
    int id;
    string name;
    Student()
    {
        cout << "Default Constructor called\n";
        id = 1;
        name = "Pranav";
    }
    Student(int sid, string sname)
    {
        cout << "Parametrized Constructor with 2 args called\n";
        id = sid;
        name = sname;
    }
    Student(int sid)
    {
        cout << "Parametrized Constructor with 1 args called\n";
        id = sid;
        name = "Sebin";
    }
    void disp()
    {
        cout << "id = " << id << "  Name is " << name << endl;
    }
};
int main()
{
    Student s1, s2(2,"Arunraj"), s3(3);
    s1.disp();
    s2.disp();
    s3.disp();
    return 0;
}