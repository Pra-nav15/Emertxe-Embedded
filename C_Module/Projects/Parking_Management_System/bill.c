#include<stdio.h>
#include"main.h"

void print_bill(Vehicle* vehicle, float amount)
{
    printf("=====================================\n");
    printf("\nParking Bill\n");
    printf("=====================================\n");
    printf("Vehicle Slot id      :           %d\n", vehicle->slot_id);
    printf("Vehicle Plate Number :           %s\n", vehicle->plate);
    printf("Vehicle Owner Name   :           %s\n", vehicle->owner);
    printf("Vehicle Type         :           %s\n", vehicle->vehicle_type);
    printf("Vehicle Entry Time   :           %s\n", ctime(&vehicle->entry_time));
    printf("Vehicle Exit Time    :           %s\n", ctime(&vehicle->exit_time));
    long duration = vehicle->exit_time - vehicle->entry_time;
    int hours = duration / 3600;
    int minutes = (duration % 3600) / 60;
    printf("Total Park Duration  :           %dHH:%dMM\n",hours, minutes);
    printf("Total Amount         :           %f\n", amount);
    printf("=======================================\n");
}