/* /* 
Name: Pranav Prasad
Date: 19/08/2025
Description: Program to find 3rd largest element in an array
Sample Input: Enter the elements into the array: 5 1 4 2 8
Sample Output: Third largest element of the array is 4
#include <stdio.h>

int third_largest(int arr[], int);

int main()
{
    int size, ret, i;
    
    scanf("%d", &size);
    
    int arr[size];
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    ret = third_largest(arr, size);
    
    printf("Third largest element of the array is %d\n", ret);
    
    return 0;
}

int third_largest(int arr[], int size)
{
    int i, largest, sec_largest, third_largest;
    for(i = 0; i < size; i++)
    {
        if(arr[i] > largest)
        {
            third_largest = sec_largest;
            sec_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > sec_largest && arr[i] < largest)
        {
            third_largest = sec_largest;
            sec_largest = arr[i];
        }
        else if(arr[i] > third_largest && arr[i] < sec_largest)
        {
            third_largest = arr[i];
        }
    }
    return third_largest;
}
 */
/*
Name: Pranav Prasad
Date: 19/08/2025
Description: Program to find 3rd largest element in an array
Sample Input: Enter the elements into the array: 5 1 4 2 8
Sample Output: Third largest element of the array is 5
*/

#include <stdio.h>

int third_largest(int arr[], int);

int main()
{
    int size, ret, i;
    
    scanf("%d", &size);
    
    int arr[size];
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    ret = third_largest(arr, size);
    
    printf("Third largest element of the array is %d\n", ret);
    
    return 0;
}

int third_largest(int arr[], int size)
{
    int i, largest, sec_largest, third_largest;
    for(i=0;i<size;i++)
    {
        if(arr[0]>arr[1] && arr[1]>arr[2])
        {
            largest=arr[0];
            sec_largest=arr[1];
            third_largest=arr[2];
        }
        else if(arr[0]<arr[1] && arr[1]>arr[2])
        {
            largest=arr[1];
            sec_largest=arr[0];
            third_largest=arr[2];
        }
        else if(arr[0]>arr[1] && arr[1]<arr[2])
        {
            largest=arr[0];
            sec_largest=arr[2];
            third_largest=arr[1];
        }
        else if(arr[0]<arr[1] && arr[1]<arr[2])
        {
            largest=arr[2];
            sec_largest=arr[1];
            third_largest=arr[0];
        }
    }
    for(i = 0; i < size; i++)
    {
        if(arr[i] > largest)
        {
            third_largest = sec_largest;
            sec_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > sec_largest && arr[i] < largest)
        {
            third_largest = sec_largest;
            sec_largest = arr[i];
        }
        else if(arr[i] > third_largest && arr[i] < sec_largest)
        {
            third_largest = arr[i];
        }
    }
    return third_largest;
}
