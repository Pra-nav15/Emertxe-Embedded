
/*
Name:Pranav Prasad
Date:19/08/2025
Description:Program to find 2nd largest element in an array
Sample Input: Enter the elements into the array: 5 1 4 2 8
Sample Output: Second largest element of the array is 5
#include <stdio.h>

int sec_largest(int arr[], int);

int main()
{
    int size,ret,i,*ptr;
    
    //Read size from the user
    //printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int arr[size];
    ptr=arr;
    //Read elements into the array
    //printf("Enter the elements into the array: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    //funtion call
    ret = sec_largest(arr, size);
    
    printf("Second largest element of the array is %d\n", ret);
}
int sec_largest(int arr[], int size)
{
    int i,largest,smallest,sec_largest=0;
    //sorting array elements is ascending order
    for(i=0;i<size;i++)
    {
        if(arr[i]>arr[i+1])
        {
            largest=arr[i];
        }
        else
        {
            smallest=arr[i];
        }
    }
    for(i=0;i<size;i++)
    {
        if(arr[i]>sec_largest && arr[i]<largest)
        {
            sec_largest=arr[i];
        }
    }
    return sec_largest;
}
*/
/*
Name:Pranav Prasad
Date:19/08/2025
Description:Program to find 2nd largest element in an array
Sample Input: Enter the elements into the array: 5 1 4 2 8
Sample Output: Second largest element of the array is 5
*/

#include <stdio.h>

int sec_largest(int arr[], int);

int main()
{
    int size,ret,i,*ptr;
    
    //Read size from the user
    //printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int arr[size];
    ptr=arr;
    //Read elements into the array
    //printf("Enter the elements into the array: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    //funtion call
    ret = sec_largest(arr, size);
    
    printf("Second largest element of the array is %d\n", ret);
}
int sec_largest(int arr[], int size)
{
    int i,largest,smallest,sec_largest;
    //sorting array elements is ascending order
    if(arr[0]>arr[1])
    {
        largest=arr[0];
        sec_largest=arr[1];
    }
    else
    {
        largest=arr[1];
        sec_largest=arr[0];
    }
    for(i=2;i<size;i++)
    {
        if(arr[i]>largest)
        {
            sec_largest=largest;
            largest=arr[i];
        }
        else if(arr[i]>sec_largest)
        {
            sec_largest=arr[i];
        }
    }
    return sec_largest;
} 