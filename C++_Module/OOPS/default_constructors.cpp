#include<iostream>
using namespace std;
class Student
{
    int id;
    string name, address;
public:
    Student()
    {
        cout << "Default Constructor is called\n";
        id = 25;
        name = "Pranav";
        address = "Bangalore";

    }
    void print_details()
    {
        cout << "\nid " << id << "\nname " << name << "\naddress " << address << endl;
    }
};
int main()
{
    Student s1, s2, s3;
    s1.print_details();
    s2.print_details();
    s3.print_details();
}