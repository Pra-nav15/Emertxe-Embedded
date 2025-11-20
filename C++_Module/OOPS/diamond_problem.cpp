#include<iostream>
using namespace std;
/* Diamond Problem is well known issue in c++ that arises when multiple types of inheritance.
It is called as diamond problem because of diamond shape formed by the inherited graph */
class A
{
public:
    void func()
    {
        cout << "A:func()" << endl;
    }
};

class B : public A {
};
class C : public A {
};
class D : public B,public C {
};

/*
In this example A is base class,B and C are derived claases from A,D is derived classs from B and C
The Problem arises due to D inherits two copies of A one through B and other through C.This leads to ambiguity when
trying to access members of A tthrough D.If you call fun() on a object of type D,theer will be compiler error*/

/* int main()
{
    D d;
    d.func(); //error ambigous access to func()
    return 0;
} */

/* To resolve this Diamond Problem we haev 2 solutions
1. Virtual Inheritance-You can use virtual inheritance to ensure that only one copy of the base clasis inherited .To do this modify inheitance of B and C tom use virtual keyword:
    class B : virtual public A{
    };
    };
    class C : virtual public A{
    };
    };
    By using virtual inheritance ,you ensure D inherits only one copy of A.

2. Scope Resolution Operator: Another solution is to use scope resolution
operator (::) to explicitly specify the copy of base class you want to access: resolving ambiguity
*/

int main()
{
    D d;
    d.B::func(); //Calls func() from B's copy of A
    d.C::func(); //Calls func() from C's copy of A
    return 0;
}
