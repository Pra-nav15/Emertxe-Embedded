#include<stdio.h>
typedef struct Bank
{
    long acc_number;
    int balance;
    int transaction_history[100];
    int transaction_count;
}Bank;
int main()
{
    Bank b={0 , 0,{0},0};
    printf("Welcome To Pranav's Bank....\n");
    int option, amount;
    printf("Please Enter your Account Number: ");
    scanf("%lu", &b.acc_number);
    while (1)
    {
        printf("Select The Below Services\n1.Deposit\n2.Withdrawal\n3.Transaction Details\n4.Balance\n5.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter The Amount to Deposit : ");
            scanf("%d", &amount);
            if (amount > 100000)
            {
                printf("Huge Deposit cannot be processed\n");
            }
            else if (amount <= 0)
            {
                printf("Please Enter a Valid Amount\n");
            }
            else
            {
                b.balance += amount;
                b.transaction_history[b.transaction_count++] = amount;
                printf("Successfully Deposited Amount\n");
            }
            break;
        case 2:
            printf("Enter The Amount to Withdraw : ");
            scanf("%d", &amount);
            if (amount > 100000)
            {
                printf("Huge Withdraw cannot be processed\n");
            }
            else if (amount <= 0)
            {
                printf("Please Enter a Valid Amount\n");
            }
            else if (amount >= b.balance)
            {
                printf("Insufficient Balance\n");
            }
            else
            {
                b.balance -= amount;
                b.transaction_history[b.transaction_count++] = -amount;
                printf("Successfully Withdrawn Amount\n");
            }
            break;
        case 3:
            if (b.transaction_count == 0)
            {
                printf("No Transactions Completed\n");
            }
            else
            {
                printf("Total Transactions is %d\n", b.transaction_count);
                int count = 1;
                for (int i = 0;i < b.transaction_count;i++)
                {
                    printf("%d.\t%d\n", count++,b.transaction_history[i]);
                }
            }
            break;
        case 4:
            if (b.balance <= 0)
            {
                printf("Your Account has been detected with less balance\n");
            }
            else
            {
                printf("Account Balance is %d\n", b.balance);
            }
            break;
        case 5:
            printf("Thank You for using our services\n");
            return 0;
        default:
            printf("Invalid Option Selected\n");
        }
    }
}
