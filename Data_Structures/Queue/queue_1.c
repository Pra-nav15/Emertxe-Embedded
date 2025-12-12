#include <stdio.h>

int main()
{
    int queue[5];
    int front = -1;
    int rear = -1;
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        if ((rear + 1) % size == front) 
        {
            printf("Full\n");
            return 0;
        }
        else
        {
            if (front == -1)
            {
                 front = 0; 
            }
            rear = (rear + 1) % size;
            queue[rear] = (i + 1) * 10; 
        }
    }
    while (front != -1)
    {
        printf("%d\n", queue[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    return 0;
}
