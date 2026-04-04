#include<stdio.h>
#include"main.h"

void exit_vehicle(void)
{
    char plate[15];
    printf("Enter the Vehicle Plate Number: ");
    scanf("%s",plate);
    int index = findByPlate(plate);
    if (index == FAILURE)
    {
        printf("Vehicle Not Found\n");
        return;
    }
    vehicles[index].exit_time = time(NULL);
    float amount = calculateFare(&vehicles[index]);
    releaseSlot(vehicles[index].slot_id);
    print_bill(&vehicles[index], amount);
}
