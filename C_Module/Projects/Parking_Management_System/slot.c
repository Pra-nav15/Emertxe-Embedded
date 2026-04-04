#include<stdio.h>
#include<string.h>
#include"main.h"

int allocateSlot(char* plate)
{
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        if (slots[i].is_occupied == 0)
        {
            slots[i].is_occupied = 1;
            strcpy(slots[i].plate, plate);
            return i + 1;
        }
    }
    return FULL;
}

void releaseSlot(int slot_id)
{
    if (slot_id > 0 && slot_id <= MAX_SLOTS)
    {
        slots[slot_id - 1].is_occupied = 0;
    }
}

void check_slot(void)
{
    printf("Parking Slot Status\n");
    printf("---------------------------------\n");
    printf("Vacant --- > [  ]\n");
    printf("Occupied --- > [ X ]\n");
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        if (slots[i].is_occupied)
        {
            printf("(%d)-->%3s\t", i + 1, "[ X ]");
        }
        else
        {
            printf("(%d)-->%3s\t", i + 1, "[  ]");
        }
        if ((i + 1) % 5 == 0)
        {
            printf("\n\n");
        }
    }
}