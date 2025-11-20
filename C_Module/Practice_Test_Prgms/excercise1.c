#include<stdio.h>
int main(){
    int option;
    printf("Enter the value: ");
    scanf("%d", &option);
    switch(option)
    {
        case 10:
         printf("value is 10\n");
        break;
        case 20:
         printf("value is 20\n");
        break;
        case 30:
         printf("value is 30\n");
        break;
        case 40:
         printf("value is 40\n");
        break;
        default:
         printf("Try Again\n");
    }
    return 0;
}