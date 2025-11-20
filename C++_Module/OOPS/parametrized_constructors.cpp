#include<iostream>
#include<cstring>
using namespace std;
class Student
{
public:
    int id;
    string name, address;
    Student(int x, char* s); //Parametrized constructor
    //Fun def can be written outside class with the scope operator
    Student::Student(int x, char * s,char * a)
    {
        id = 25;
        name = (char*)malloc(sizeof(char) * 10);
        strcpy(name, s);
        address = (char*)malloc(sizeof(char) * 20);
        strcpy(address, a);
    }
    void print_details()
    {
        cout << "\nid " << id << "\nname " << name << "\naddress " << address << endl;
    }
};
int main()
{
    Student e(25, (char*)"Tingu", (char*)"Bangalore");
    cout << "The Id is " << e.id << endl;
    cout << "The Name is " << e.name << endl;
    cout << "The Address is " << e.address << endl;
    

}