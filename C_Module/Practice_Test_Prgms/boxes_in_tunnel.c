/*oxes through a Tunnel

A tunnel has a height of 41 feet.
You are given a series of boxes, each with length, width, and height.

If the height of a box is less than 41, the box can pass through the tunnel.

For each such box, print its volume (length × width × height).

Otherwise, ignore that box (no output).

Input Format:

The first line contains an integer n, the number of boxes.

The next n lines each contain three integers: length width height.

Output Format:

For each box that can pass through the tunnel, print its volume on a new line.

Constraints:

1 ≤ n ≤ 100

1 ≤ length, width, height ≤ 100

Sample Input:

4
5 5 5
1 2 40
10 5 41
7 2 42


Sample Output:

125
80*/
#include<stdio.h>
int main()
{
    int n,length,width,height,i,volume=0;
    printf("Enter the number of boxes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the length ,breadth and height of box %d: ",i);
        scanf("%d %d %d",&length,&width,&height);
        if(height<41)
        {
            volume=length*width*height;
        }
        else
        {
            continue;
        }
        printf("Volume is : %d",volume);
        printf("\n");
    }
    return 0;
}