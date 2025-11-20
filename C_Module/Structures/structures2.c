#include <stdio.h>
#include<string.h>
struct Address {
    char city[20];
    int pincode;
};

struct Employee {
    char name[20];
    int id;
    struct Address addr;   // nested struct
};

struct Company {
    char cname[20];
    struct Employee emp;   // Employee struct nested
};

int main() {
    struct Company c1;

    strcpy(c1.cname, "Qualcomm");
    strcpy(c1.emp.name, "Pranav");
    c1.emp.id = 501;
    strcpy(c1.emp.addr.city, "Thrissur");
    c1.emp.addr.pincode = 682001;

    printf("Company: %s\n", c1.cname);
    printf("Employee: %s\n", c1.emp.name);
    printf("City: %s\n", c1.emp.addr.city);
    printf("Pincode: %d\n", c1.emp.addr.pincode);

    return 0;
}
