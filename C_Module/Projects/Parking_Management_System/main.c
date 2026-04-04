#include<stdio.h>
#include "main.h"

Vehicle vehicles[MAX_VEHICLES];
ParkingSlot slots[MAX_SLOTS] = {0};
int vehicle_count = 0;
int main()
{
    int choice;
    printf("Welcome to Parking Management System\n");
    while (1)
    {
        printf("Select the Below Services to Continue :\n");
        printf("1.Park a Vehicle\n2.Exit a Vehicle\n3.Check Slot Availability\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            park_vehicle();
            break;
        case 2:
            exit_vehicle();
            break;
        case 3:
            check_slot();
            break;
        case 4:
            printf("Thank You for Choosing our Service \n");
            break;
        case 5:
            printf("Exiting........\n");
            return 0;
        default:
            printf("Invalid Choice ,Try Again\n");
        }
    }
}
