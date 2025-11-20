#include<stdio.h>
struct Shop{
    int s1no;
    char name[100];
    int quantity;
    float cost;
    float amount;
};
int main()
{
    int totalquantity=0;
    float totalamount=0;
    struct Shop Bill[3];
    for(int i=1;i<=3;i++)
    {
       printf("Enter item %d : ",i);
       scanf("%s",Bill[i].name);
       printf("Enter no of pieces : ");
       scanf("%d",&Bill[i].quantity);
       printf("Enter cost: ");
       scanf("%g",&Bill[i].cost);
       Bill[i].amount=Bill[i].quantity * Bill[i].cost;
    }
    printf("----------------------------------------------------\n");
    printf("SlNo      Name       Quantity      Cost       Amount\n");
    printf("----------------------------------------------------\n");
    for(int i=1;i<=3;i++)
    {
       printf("%d\t",i);
       printf("%-13s",Bill[i].name);
       printf("%-2d\t",Bill[i].quantity);
       printf("%-18g\t",Bill[i].cost);
       printf("%-25g\t",Bill[i].amount);
       totalquantity+=Bill[i].quantity;
       totalamount+=Bill[i].amount;
       printf("\n");
    }
    printf("----------------------------------------------------\n");
    printf("Total");
    printf("%-25d %-25g\n",totalquantity,totalamount);
    return 0;
}