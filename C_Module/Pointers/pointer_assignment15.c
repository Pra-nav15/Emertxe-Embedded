#include <stdio.h> 
void fun(int arr1[], int size, int arr2[], int *new_size); 
int main() 
{ 
    int size,new_size=0; 
    printf("Enter the size: "); 
    scanf("%d",&size); 
    int arr1[size],arr2[size]; 
    printf("Enter elements into the array: "); 
    for(int i=0;i<size;i++) 
    { 
        scanf("%d",&arr1[i]); 
    } 
    fun(arr1,size,arr2,&new_size); 
    for(int i=0;i<new_size;i++) 
    { 
        printf("%d",arr2[i]); 
    } 
} 
void fun(int arr1[], int size, int arr2[], int *new_size) 
{ 
    arr2[0]=arr1[0]; 
    (*new_size)++; 
    int flag; 
    for(int i=1;i<size;i++) 
    { 
        flag=0; 
        for(int j=0;j<*new_size;j++) 
        { 
            if(arr1[i]==arr2[j]) 
            { 
                flag=1; 
                break; 
            } 
        } 
        if(flag==0) 
        { 
            arr2[*new_size]=arr1[i]; 
            (*new_size)++; 
        } 
    } 
}
