#include<iostream>
using namespace std;
class Student
{
    int id;
    string name, address;
    public:
    Student(int sid,string sname,string saddress)//Parametrized constructor
    {
        cout << "Constructor called\n";
        id = sid;
        name = sname;
        address = saddress;
    }
    void print_details()
    {
        cout << "\nid " << id << "\nname " << name << "\naddress " << address << endl;
    }
};
int main()
{
    Student s1(1, "Pranav", "Bangalore"), s2(2, "Sebin", "Thrissur"), s3(3, "Vivek", "Palakkad");
    s1.print_details();
    s2.print_details();
    s3.print_details();
}