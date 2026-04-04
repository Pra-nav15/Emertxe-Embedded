#include<stdio.h>
#include<time.h>
#include"main.h"

void park_vehicle(void)
{
    char choice;
    int slot = 0;
    while (1)
    {
        printf("Do you want to park vehicle? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
        {
            break;
        }
        Vehicle v;
        printf("Enter the Vehicle ID(Number Plate): ");
        scanf("%s", v.plate);
        if (validate_vehicle_plate(v.plate) == FAILURE)
        {
            printf("Vehicle Number Plate Not Valid\n");
            continue;
        }
        if (isduplicate(v.plate) == SUCCESS)
        {
            printf("Vehicle with duplicate plate found\n");
            continue;
        }
        printf("Enter the Owner Name: ");
        scanf(" %[^\n]", v.owner);
        if (validate_vehicle_owner(v.owner) == FAILURE)
        {
            printf("Owner Name is Invalid\n");
            continue;
        }
        printf("Enter the Vehicle Type: ");
        scanf("%s", v.vehicle_type);
        if (validate_vehicle_type(v.vehicle_type) == FAILURE)
        {
            printf("Invalid Vehicle Type\n");
            continue;
        }
        slot = allocateSlot(v.plate);
        if (slot == FULL)
        {
            printf("Parking Full\n");
            continue;
        }
        v.slot_id = slot;
        v.entry_time = time(NULL);
        vehicles[vehicle_count] = v;
        vehicle_count++;
        printf("Vehicle Parked at Slot %d\n", slot);
    }
}
