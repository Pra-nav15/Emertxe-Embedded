/*
Name:Pranav Prasad
Date:19/08/2025
Description:Program to print the values in sorted order without modifying or copying array
Sample Input: Enter 7 elements 
              1 3 2 5 4 7 6
Sample Output: After sorting: 1 2 3 4 5 6 7
               Original array values 1 3 2 5 4 7 6
*/
#include <stdio.h>

void print_sort(int arr[], int size);

int main()
{
    int size, iter;
    
    //printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int arr[size];
    
    //printf("Enter the %d elements\n",size);
    for (iter = 0; iter < size; iter++)
    {
        scanf("%d", &arr[iter]);
    }
    print_sort(arr, size);
    printf("\n");
    printf("Original array values ");
    for (iter = 0; iter < size; iter++)
    {
        printf("%d ", arr[iter]);
    }

    
}
void print_sort(int arr[], int size)
{
    int largest=arr[0],iter,smallest=arr[0],sec_smallest,iter1;
    for(iter=0;iter<size;iter++)
    {
        if(largest<arr[iter])
        {
            largest=arr[iter];
        }
        if(smallest>arr[iter])
        {
           smallest=arr[iter];
        }  
    }
    sec_smallest=largest;
    printf(" After sorting ");
    for(iter=0;iter<size;iter++)
    {
        for(iter1=0;iter1<size-1;iter1++)
        {
            if(arr[iter1]>smallest && arr[iter1]<sec_smallest)
            {
               sec_smallest=arr[iter1];
            }
        }
        printf("%d ",smallest);
        smallest=sec_smallest;
        sec_smallest=largest;
    }
    return ;
}