#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"main.h"

int validate_vehicle_plate(char* plate)
{
    int plate_len = strlen(plate);
    if (plate_len != 9)
    {
        printf("Number Plate is Invalid\n");
        return FAILURE;
    }
    for (int i = 0;i < plate_len;i++)
    {
        if (!isalnum(plate[i]))
        {
            printf("Given Number Plate is Invalid,Should Contain only Alphanumeric Characters");
            return FAILURE;
        }
    }
    return SUCCESS;
}

int validate_vehicle_type(char* type)
{
    if (strcmp(type, "Car") && strcmp(type, "Bike") && strcmp(type, "Auto") && strcmp(type, "Minibus"))
    {
        printf("Parking Allowed only For Cars, Bikes , Autos and Minibuses\n");
        return FAILURE;
    }
    return SUCCESS;
}

int validate_vehicle_owner(char* name)
{
    int name_len = strlen(name);
    if (name_len < 2)
    {
        printf("Name is not Valid\n");
        return FAILURE;
    }
    for (int i = 0;i < name_len;i++)
    {
        if (!isalpha(name[i]))
        {
            printf("Given Name is Invalid,Only Alphabets allowed in name\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

int findByPlate(char* plate)
{
    for (int i = 0; i < vehicle_count; i++)
    {
        if (strcmp(vehicles[i].plate, plate) == 0)
        {
            return i;
        }
    }
    return FAILURE;
}

int isduplicate(char* plate)
{
    for (int i = 0; i < vehicle_count; i++)
    {
        if (strcmp(vehicles[i].plate, plate) == 0)
        {
            return SUCCESS;
        }
    }
    return FAILURE;
}